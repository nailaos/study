# 深入理解计算机系统

#### 第二章 信息的表示和处理
- 信息存储
  - 十六进制表示法
  - 字数据大小
  - 寻址和字节顺序
  - 表示字符串
  - 表示代码
  - 布尔代数简介
  - c语言中的位级运算
  - c语言中的逻辑运算
  - c语言中的移位运算
- 整数表示
  - 整型数据类型
  - 无符号数的编码
  - 补码编码
  - 有符号数和无符号数的相互转换
  - c语言中的有符号数和无符号数
  - 扩展一个数字的位表示
    - 零扩展和符号扩展
  - 截断数字
    - 直接截
  - 关于有符号数和无符号数的建议
- 整数运算
  - 

#### 第三章 程序的机器级表示

- 学习目标：

  1. c语言，汇编代码以及机器代码之间的关系

  2. 数据处理和控制实现

  3. 过程实现

  4. 数据结构

  5. 内存访问越界

  6. GDB调试

- 3.1 历史观点
- 摩尔定律：芯片上晶体管数量的增长规律
- 3.2 程序代码

  - 隐藏的处理器

    |      处理器名称      |                 作用                 |
    | :------------------: | :----------------------------------: |
    | 程序计数器（**PC**） |     存储下一条指令在内存中的地址     |
    |      整数寄存器      |          存储地址或整数数据          |
    |     条件码寄存器     | 最近执行的算术或者逻辑指令的状态信息 |
    |      向量寄存器      |    存放一个或多个整数或者浮点数值    |

  - 机器代码特性

    - x86-64指令长度从1到15个字节不等。常用的指令字节数少
    - 反汇编器只是基于机器文件中的字节序列
    - 'q'后缀可省略

  - 程序使用汇编代码的方法

    - 使用汇编语言编写函数，链接的时候链接到一起
    - 使用内联汇编特性

- 3.3 数据格式

  - **TODO**：列出类型对应的字节和后缀表

- 3.4 访问信息

  - **TODO**：
    - 1. 寄存器表
      2. 操作数类型
      3. 数据传送（后缀匹配，传送示例 and movabsq）
      4. 扩展

- 3.5 算术和逻辑操作

  - **TODO**：
    - 1. 移位
      2. 特殊的算术操作

- 3.6 控制

  - 条件码
  - 整数和浮点数具有不同的指令和硬件
  - 跳转（goto风格，直接和间接跳转，相对和绝对跳转编码）
  - 全局变量的访问依赖rip寄存器，且偏移量动态变化
  - 条件控制和条件传送
    - 前者改变程序的控制流，会发生预测错误
    - 后者不改变控制流，只是根据条件决定是否执行某个操作，更有效率，但是只有在满足限定条件的情况下才可以使用，比如分支里面有副作用就不可以
      - 计算分支预测处罚时间：**_T_**<sub>ran</sub> = **_T_**<sub>OK</sub> + 0.5 **_T_**<sub>MP</sub>
      - 性能不一定总是好，因为会浪费计算资源
  - 循环
    - do-while比较基础，while和for是等价的，两种转换方式：jump to middle，guarded-do
  - switch语句
    - 情况数量较多，值的范围跨度比较小，就会使用跳转表

- 3.7 过程
  - 转移控制和数据传送
    - PC，%rsp，(%rsp)的变化
    - 参数大于6个时，通过栈去传递
  - 栈上和寄存器上的存储
    - 栈帧
    - 返回地址指的就是返回调用者的进程后应该执行的语句所在的位置，返回地址之前存的就是额外的参数，这样被调用者就可以先读取参数进行计算，然后可以继续使用栈，而不用担心因为栈指针的变化，而不知道偏移量无法访问额外参数的问题
    - 寄存器使用惯例
  - 递归过程(和一般函数调用并无较大区别)
- 3.8 数组分配和访问
  - 基本原则
  - 指针运算
    - 两个指针之差等于地址之差除以该数据类型的大小
      `&E[i] - E = i`
  - 嵌套数组
    - 索引变为伸缩的偏移量即可

#### 第七章 链接

- 7.1 编译器驱动程序
  - 编译命令
  ```shell
  gcc -Og -o prog main.c sum.c
  # C预处理器，将源文件翻译为一个ASCII码的中间文件main.i
  cpp [other aruguments] main.c main.i
  # C编译器，将main.i翻译为汇编语言文件main.s
  ccl main.i -Og [other comments] -o main.s
  # 运行汇编器，将main.s翻译为一个可重定位目标文件
  as [other arguments] -o main.o main.s
  # 链接
  ld -o prog [system object files and args] main.o sum.o
  ```
- 7.2 静态链接
  - 链接器必须完成两个任务
    - 符号解析
    - 重定位
- 7.3 目标文件
  - 目标文件有三种形式
    - 可重定位目标文件
    -
    -
- 7.4 可重定位目标文件
  - ELF header
  - .text
  - .dodata
  - .bss
  - .symtab
  - .rel.text
  - .rel.data
  - .debug
  - .line
  - .strlab
  - 节头部表
- 7.5 符号和符号表
  - 三种符号
    - 全局符号
    - 外部符号
    - 局部符号
  - 符号表
- 7.6 符号解析
  - 解析多重定义全局符号
  - 与静态库链接
  - 链接器如何使用静态库来解析文件
- 7.7 重定位
  - 重定位由两步组成
    - 重定位节和符号定义
    - 重定位节中的符号引用
      - 依赖于可重定位目标模块中重定位条目的数据结构
  - 重定位条目
    - 重定位PC相对引用
    - 重定位绝对引用
- 7.8 可执行目标文件
  - 只读内存段(代码段)
  - 读/写内存段(数据段)
  - 不加载到内存的符号表和调试信息
- 7.9 加载可执行目标文件
  - 内存映像
- 7.10 动态链接共享库
  - 加载器加载和执行文件的时候，在.interp会看到动态链接器的路径名，然后加载和执行该动态链接器，动态链接器通过重定位完成链接
    - 重定位filename.so的文本和数据到某个内存段
    - 重定位程序中对filename.so定义的符号的引用
    - 简单来说就是遇到动态链接，就让动态链接器去把文件中的内容加载内存中，然后告诉程序放的位置，这样程序就可以找到了
- 7.11 从应用程序中加载和链接共享库
  - java可以调用"本地的"c和c++函数，就是利用共享库，先将函数编译到一个共享库中(foo.so)，然后执行到foo函数的时候，动态链接和加载foo.so就可以了
- 7.12 位置无关代码
  - PIC数据引用
    - 利用代码段和数据段的距离总是保持不变，设计一个全局偏移量表
  - PIC函数调用
    - 依赖GOT和PLT(过程链接表)
    - 延迟解析地址
- 7.13 库打桩机制

#### 第九章 虚拟内存

- 前言
  - 虚拟内存(VM)是对主存的抽象概念
  - 虚拟内存是硬件异常，硬件地址翻译，主存，磁盘文件，和内核软件的完美交互，为每个进程提供一个**大的**，**一致的**和**私有的**地址空间
  - 提供三个重要的能力
  1. 将主存看作是一个存储在磁盘上的地址空间的告诉缓存，在主存中只保存活动区域，并根据需要在主存和磁盘之间来回传送数据，通过这种方式，高效使用主存
  2. 为每个进程提供一致的地址空间，简化内存管理
  3. 保护每个进程的地址空间不被其他进程破坏
  - 本章从两个角度来看虚拟内存，一是描述虚拟内存是如何工作的，二是如何使用和管理虚拟内存
- 9.1 **物理和虚拟寻址**
  - 物理寻址
  - 虚拟寻址
    - 需要内存管理单元(MMU)翻译，MMU利用主存中的查询表来**动态**翻译虚拟地址，查询表的内容由操作系统管理
- 9.2 地址空间
  - 非负整数地址的**有序集合**
    - **线性地址空间**: 整数连续
    - **虚拟地址空间**: 用于生成虚拟地址的线性地址空间
    - **物理地址空间**: 系统中物理内存的M个字节
    - n位地址空间: 包含$2^n$个地址的虚拟地址空间
    - 主存中的每字节都对应一个选自虚拟地址空间的虚拟地址和一个选自物理地址空间的物理地址
- 9.3 虚拟内存作为缓存的工具
  - DRAM的缓存的组织结构
    - 因为大的不命中的处罚和访问第一个字节的开销，虚拟页往往很大
    - DRAM的缓存是全关联的，即任何虚拟页往往都可以放到任何物理页中
    - DRAM使用写回，而不是直写
  - 页表
    - **页表**: 存放在物理内存的数据结构，是一个**页表条目**的数组，将虚拟页映射到物理页
    - **页表条目**: 有效位和n位地址字段，其中有效位表示物理页是否缓存该虚拟页
  - 页命中
  - 缺页
    - DRAM缓存不命中
    - **按需页面调度**: 当有不命中发生时，才换入页面的策略
  - 分配页面
    - 在磁盘上创建空间并且更新PTE
  - 局部性
    - **工作集**: 又称**常驻集合**，指的是局部性保证在任意时刻，程序将趋向于在一个较小的活动页面集合上工作，这个集合就是工作集
    - **抖动**: 工作集超出了物理内存的大小，程序性能变得很慢
- 9.4 虚拟内存作为内存管理的工具
  - 多个虚拟页面可以映射到同一个物理页面上
  - **简化链接**
  - **简化加载**
  - **简化共享**
  - **简化内存分配**
- 9.5 虚拟内存作为内存保护的工具
  - 在PTE增加许可位，若违反许可条件，就会将控制传递给一个内核中的异常处理程序，一般将异常报告为"段错误(segmentation fault)"
- 9.6 地址翻译
  - 页面命中时CPU硬件执行的步骤
  - 页面未命中时CPU硬件执行的步骤
  - 结合高速缓存和虚拟内存
    - 地址翻译发生在高速缓存查找之前
  - 利用TLB加速地址翻译
    - 地址翻译都是在MMU中完成的
  - 多级页表
    - 两个方面减少了内存要求
    1. 一级页表的一个PTE是空的，那对应的二级页表不会存在
    2. 只有一级页表才总是需要在主存中，需要时调出二级页表即可，只有最经常使用的二级页表才需要缓存在主存中(主存是物理地址空间的一部分，所以这里的意思是不频繁使用的还是存储在物理地址空间中？？？)
- 9.7 案例研究
- 9.8 内存映射
  - **内存映射**: Linux将虚拟内存区域和一个磁盘上的对象关联起来，初始化这个区域内存的内容的过程
  - 虚拟内存区域可以映射到一下两种
    - Linux系统文件中的普通文件
    - 匿名文件
  - 共享对象
- 9.9 动态内存分配
  - 隐式空闲链表
  - 显式空闲链表
- 9.10 垃圾收集
  - 垃圾收集器将内存视为一张有向可达图，对于节点p，若存在有向路径，则为可达，任何时刻，不可达节点对应于垃圾
  - C程序的Mark & Sweep收集器必须是保守的，根本原因是C语言不会使用类型信息来标记内存位置，因此，像int或者float这样的标量可以伪装成指针
- 9.11 C程序中常见的与内存有关的错误
  - 间接引用坏指针
  ```c
    scanf("%d", &val);
    scanf("%d", val);
  ```
  - 读未初始化的内存
  ```c
    int *y = (int *)Malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        y[i] += i;
    //应该显式地将y初始化为0，或者调用calloc
  ```
  - 允许栈缓冲区溢出
  ```c
    char buf[64];
    gets(buf);
  ```
  - 假设指针和它们指向的对象是相同大小的
  ```c
    int **A = (int **)Malloc(n * sizeof(int));
    int **A = (int **)Malloc(n * sizeof(int *));  //Right
  ```
  - 造成错位错误
  ```c
    int **A = (int **)Malloc(n * sizeof(int *));
    for(int i = 0; i <= n; i++)
        A[i] = (int *)Malloc(n * sizeof(int));
    //覆盖了A数组后面的某个内存位置
  ```
  - 引用指针，而不是它所指向的对象
  ```c
    int *A = (int *)Malloc(n * sizeof(int));
    *A--;
    (*A)--;  //Right
  ```
  - 误解指针运算
  ```c
    int *search(int *p, int val) {
        while(*p && *p != val) {
            p += sizeof(int);
            p++;  //Right
        }
    }
  ```
  - 引用不存在的变量
  ```c
    int *stackref() {
        int val;
        return &val;
    }
  ```
  - 引用空闲堆块中的数据
  ```c
    int *x, *y;
    int *x = (int *)Malloc(n * sizeof(int));
    int *y = (int *)Malloc(n * sizeof(int));
    free(x);
    for(int i = 0; i < n; i++)
        y[i] = x[i]++;
  ```
  - 引起内存泄漏
  ```c
    void leak(int n) {
        int *x = (int *)Malloc(n * sizeof(int));
        return;
    }
  ```
- 9.12 小结
  - 虚拟内存是对主存的一个抽象。支持虚拟内存的处理器通过使用一种叫做虚拟寻址的间接形式来引用主存。处理器产生一个虚拟地址，在被发送到主存之前，这个地址会被翻译成一个物理地址。从虚拟地址空间到物理地址空间的翻译要求硬件和软件紧密合作。专门的硬件通过使用页表来翻译虚拟地址，而页表的内容是由操作系统提供的。
  - 虚拟内存提供三个重要的功能
  - 地址翻译的过程必须和系统中所有的硬件缓存的操作集成在一起。
  - 现代系统通过将虚拟内存片和磁盘上的文件关联起来，来初始化虚拟内存片，这个过程称为内存映射。
  - C程序中管理和使用虚拟内存是一件困难和容易出错的任务
