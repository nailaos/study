## 实验报告
1. 
    - 姓名：吕嘉鑫
    - 学号：2022010771
    - 班级：计22
2.  
    - **Task1**
        1. 代码
        - *coroutine_pool::serial_execute_all()*
        ```c
        bool needDo = true; // 判断是否还有进程没有完成
        while (needFinish) {
            int n = coroutines.size(); //获取进程数量                
            needDo = false;
            for (int i = 0; i < n; i++) { //遍历
                g_pool->context_id = i; //更改id为当前进程的id
                if (!coroutines[i]->finished) {
                    needDo = true; // 还有进程没有完成
                    coroutines[i]->resume(); // 恢复运行
                }
            }
        }
        ```
        - *context.S*
        ```c
        .global coroutine_switch
        coroutine_switch:
            # 保存 callee-saved 寄存器到 %rdi 指向的上下文
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
            # 保存的上下文中 rip 指向 ret 指令的地址（.coroutine_ret）
            leaq .coroutine_ret(%rip), %rcx
            movq %rcx, 120(%rdi)
            # 从 %rsi 指向的上下文恢复 callee-saved 寄存器
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
            # 取出之前保存的返回位置给%rcx
            movq 120(%rsi), %rcx
            # %rsi需要在最后恢复
            movq 16(%rsi), %rsi
            # 最后 jmpq 到上下文保存的 rip
            jmpq  *%rcx
        .coroutine_ret:
            ret
        ```
        - *yield()*
        ```c
        // 从当前协程切换到调度器
        coroutine_switch(context->callee_registers, context->caller_registers);
        ```
        - *resume()*
        ```c
        // 从调度器切换到当前协程
        coroutine_switch(context->callee_registers, context->caller_registers);
        ```
        2. 协程切换的时候栈的变化过程
        ![](photos/1.jpg "从协程切换至调度器")
        ![](photos/2.jpg "从调度器切换至协程")
        3. 协程执行过程
    - **Task2**
        1. 代码
        - *coroutine_pool::serial_execute_all()*
        ```c
        bool needDo = true; // 判断是否还有进程没有完成
        while (needFinish) {
            int n = coroutines.size(); //获取进程数量                
            needDo = false;
            for (int i = 0; i < n; i++) { //遍历
                g_pool->context_id = i; //更改id为当前进程的id
                if (!coroutines[i]->finished) {
                    needDo = true; // 还有进程没有完成
                    if (coroutines[i]->ready) // 已经准备好恢复运行
                        coroutines[i]->resume();
                    else if (coroutines[i]->ready_func()) { // 查看是否可以恢复运行
                        coroutines[i]->ready = true; // 恢复可运行状态
                        coroutines[i]->resume();
                    }
                }
            }
        }
        ```
        - *sleep(uint64_t ms)*
        ```c
        // 从 g_pool 中获取当前协程状态
        auto context = g_pool->coroutines[g_pool->context_id];
        context->ready = false;
        // 获取当前时间，更新 ready_func
        // ready_func：检查当前时间，如果已经超时，则返回 true
        auto wakeup_time = get_time() + std::chrono::milliseconds(ms);
        context->ready_func = [wakeup_time]() { return get_time() >= wakeup_time; };
        // 调用 coroutine_switch, 从当前协程切换到调度器
        coroutine_switch(context->callee_registers, context->caller_registers);
        ```
    - **Task3**
        1. 代码
        - *lookup_coroutine*
        ```c
        // 使用 __builtin_prefetch 预取容易产生缓存缺失的内存
        __builtin_prefetch(&table[probe]);
        // 并调用 yield从当前协程切换到调度器
        yield();
        ```
        2. 性能报告