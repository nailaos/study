# 协程实验 实验报告
## 徐逸群 2022010765 计22 xuyiqun22@mails.tsinghua.edu.cn
## Task 1
### 1.添加的代码
```
context::resume()
coroutine_switch(caller_registers, callee_registers); //调用协程切换函数，切换到现在的协程
```
```
coroutine_pool::serial_execute_all()
if (coroutines.size () == 0) //如果没有协程，直接返回
      return;
    bool all_done = false; //设置一个bool变量，用于判断是否所有协程都已经执行完毕
    while (!all_done) { //如果还有协程没有执行完毕，就继续执行
      all_done = true; //假设所有协程都已经执行完毕
      for (int i = 0; i < coroutines.size (); i++) { //遍历所有协程
        g_pool->context_id = i; //设置当前协程的id
        if (!coroutines[i]->finished) { //如果当前协程没有执行完毕
          all_done = false; //设置all_done为false，说明还有协程没有执行完毕
          coroutines[i]->resume (); //调用协程的resume函数，切换到当前协程
        }
      }
    }
```
```
common::yield()
coroutine_switch (context->callee_registers, context->caller_registers); //调用协程切换函数，从当前协程切换到协程调度器  
```

```
context.S
    //保存 callee-saved 寄存器到 %rdi 指向的上下文
    movq %rax, (%rdi)
    movq %rdi, 8(%rdi)
    movq %rsi, 16(%rdi)
    movq %rdx, 24(%rdi)
    movq %r8,  32(%rdi)
    movq %r9,  40(%rdi)
    movq %r10, 48(%rdi)
    movq %r11, 56(%rdi)
    movq %rsp, 64(%rdi)
    movq %rbx, 72(%rdi)
    movq %rbp, 80(%rdi)
    movq %r12, 88(%rdi)
    movq %r13, 96(%rdi)
    movq %r14, 104(%rdi)
    movq %r15, 112(%rdi)
    //保存的上下文中 rip 指向 ret 指令的地址（.coroutine_ret）
    leaq .coroutine_ret(%rip), %rcx
    movq %rcx, 120(%rdi)
    //从 %rsi 指向的上下文恢复 callee-saved 寄存器
    movq (%rsi),   %rax
    movq 8(%rsi),  %rdi
    movq 24(%rsi), %rdx
    movq 32(%rsi), %r8
    movq 40(%rsi), %r9
    movq 48(%rsi), %r10
    movq 56(%rsi), %r11
    movq 64(%rsi), %rsp
    movq 72(%rsi), %rbx
    movq 80(%rsi), %rbp
    movq 88(%rsi), %r12
    movq 96(%rsi), %r13
    movq 104(%rsi), %r14
    movq 112(%rsi), %r15
    movq 120(%rsi), %rcx
    movq 16(%rsi), %rsi
    //最后jmpq到上下文保存的 rip
    jmpq  *%rcx
```


### 2.协程切换时栈的变化过程
例如从协程1切换到协程2。
#### 首先，从协程1回到协程调度器
![微信图片_20231222163133](https://picdm.sunbangyan.cn/2023/12/22/857206b1a8389f29e148278cabca86aa.jpeg)
#### 然后，从协程调度器切换到协程2
![537f370535eb2f24e7796f997cbef5a](https://picdl.sunbangyan.cn/2023/12/22/0d5c645925d8b7ec28afb384152e0faf.jpeg)

### 3.协程是如何开始执行的
```
 uint64_t rsp = (uint64_t)&stack[stack_size - 1];
    rsp = rsp - (rsp & 0xF);

    void coroutine_main(struct basic_context * context);

    callee_registers[(int)Registers::RSP] = rsp;
    // 协程入口是 coroutine_entry
    callee_registers[(int)Registers::RIP] = (uint64_t)coroutine_entry;
    // 设置 r12 寄存器为 coroutine_main 的地址
    callee_registers[(int)Registers::R12] = (uint64_t)coroutine_main;
    // 设置 r13 寄存器，用于 coroutine_main 的参数
    callee_registers[(int)Registers::R13] = (uint64_t)this;
```
首先，每个协程首次执行时，由于rip指向coroutine_entry，所以会执行coroutine_entry函数。在coroutine_entry函数中，会调用coroutine_main函数，所以会执行coroutine_main函数，而coroutine_main函数的参数就是当前协程的指针，接着分析coroutine_main函数如下。
```
void coroutine_main(struct basic_context *context)
{
  context->run();
  context->finished = true;
  coroutine_switch(context->callee_registers, context->caller_registers);

  // unreachable
  assert(false);
}
```
coroutine_main函数中，会调用context->run()，而context->run()就是当前协程的run函数，所以会执行当前协程。而当该协程yield()的时候，会调用coroutine_switch函数，切换到协程调度器。
协程调度器通过轮询的方式，判断某个协程是否执行完毕，如果没有执行完毕，就调用协程的resume函数，切换到该协程进行执行，知道该协程执行完毕或者yield()，就会切换到协程调度器，重复这一步。
当某个协程执行完成后，会修改finished为true，从main函数直接切换到协程调度器，然后协程调度器继续轮询，直到所有协程执行完毕。调度器找不到可以执行的协程时，就会结束运行。



### 4.浮点和向量寄存器的处理
浮点和向量寄存器的处理与通用寄存器的处理类似，只需要按照浮点和向量寄存器的规范在context.S中额外保存和恢复浮点和向量寄存器，并在进行协程切换时，如通用寄存器一般进行保存和恢复即可。



## Task 2
### 1.添加的代码
```
common::sleep()
context->ready = false; //设置当前协程的ready为false
auto now_time = get_time (); //获取当前时间
context->ready_func = [now_time, ms]() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        get_time () - now_time)
        .count () >= ms;
}; //设置当前协程的ready_func，用于判断当前时间是否已经超过了应该继续执行的时间,如果已经超时，就返回true
coroutine_switch (context->callee_registers, context->caller_registers); //调用 coroutine_switch 切换到 coroutine_pool 上下文
```
```
coroutine_pool::serial_execute_all()
for (int i = 0; i < coroutines.size (); i++) {
    if (!coroutines[i]->finished) { 
        all_done = false;
        if (coroutines[i]->ready) { //如果当前协程的ready为true，说明可以继续执行
            coroutines[i]->resume (); //调用协程的resume函数，切换到当前协程来执行
        }
        else { //如果当前协程的ready为false，进一步判断当前协程的   ready_func是否返回true
            if (coroutines[i]->ready_func ()) { //如果返回true，说明已经超过等待时间，可以继续执行
                coroutines[i]->ready = true;  //设置当前协程的ready为true
                coroutines[i]->resume (); //调用协程的resume函数，切换到当前协程来执行
            }
        }
    }
}
```

### 2.sleep_sort中不同协程的运行情况
![54d455de04033a00122aca1dc4b1607](https://picdl.sunbangyan.cn/2023/12/22/5e31d01613ac733b6ed6e29f3499067d.jpeg)

### 3.更加高效的方法
可以使用阻塞机制或者使用事件驱动的方式。
#### 阻塞机制
可以利用操作系统提供的阻塞机制，当协程调用sleep函数时，就阻塞该协程，直到超过了预订的等待时间，就唤醒该协程，将该协程的ready置为true，继续执行。
#### 事件驱动
引入一种事件驱动机制，使得协程可以监听某个事件，当事件发生时，就唤醒该协程，将该协程的ready置为true，继续执行。即当协程调用sleep函数时，就监听超时事件，当超过了预订的等待时间，说明协程已经就绪，就触发超时事件，唤醒该协程，将该协程的ready置为true，继续执行。


## Task 3
### 1.添加的代码
```
binary_search::lookup_coroutine()
// 使用 __builtin_prefetch 预取容易产生缓存缺失的内存
__builtin_prefetch (&table[probe]); //预取table[probe]的内存
// 并调用 yield
yield (); //调用yield函数，切换到协程调度器
```

### 2.性能的提升效果
首先利用文件中给定的参数进行测试，得到如下结果。
![a1ba087e813d5a948c65b30df49d9d4](https://picdl.sunbangyan.cn/2023/12/22/702b67ba5dafb6f87268779c75e5c7a2.jpeg)
可以看出在此参数下，使用协程的速度要低于naive。
接下来通过命令行修改参数，来分析什么情况下使用协程的速度会高于naive，并分析原因。
#### 1.修改size
实验结果:
![c122c592c1e9c2bfe56e46fe40ed520](https://picss.sunbangyan.cn/2023/12/22/e8eab4e17b36eb2f9d48fc206accb654.jpeg)
多次重复实验并比较，可以看出，在将size修改到更小的情况下，协程的速度仍然低于naive，并且这种差距会更加显著。
分析其原因如下：协程的使用会导致额外的开销，例如协程的创建和删除，协程的切换等，在size较小时，这些时间开销占据了很大的比例，而二分查找本身计算的时间开销较小，所以协程的使用会导致速度变慢。推测在使用更大的size时，协程的速度会高于naive。
#### 2.修改loops
