- **2.0节的思考题**
    1. n最大为2236
    2. n最大为145746

- **3.2 节要求包含在报告中的内容**
    1. 找bug
        - bug1：静态检查发现solution1和solution2新的循环中sum未置0，之前的计算结果影响后面的计算
        - bug2: 静态检查发现solution1和solution2计算总和的sum都是int类型，但是最坏的情况2000*2000*10^5会发生溢出，需要改为long long类型
        - bug3: 输出调试发现solution2输出了负数，猜测为数组越界，检查后发现是第27行代码第二维应该-1，即rowsum[x + j][y + b - 1]和rowsum[x + j][y - 1]
        - bug4: 静态检查发现数组大小应该+1，否则会数组越界，即应该定义为matrix[2001][2001];
    2. 如何使用调试器单步执行程序
        - list: 列出原代码
        - break: 设置断点，可以是行号也可以是函数名
        - info break: 查看断点信息
        - run：运行
        - step: 单步执行
        - next: 单条语句执行
        - continue：继续运行
        - finish: 退出函数
        - q: 退出gdb
        - 使用调试需要在编译时加上-g,加入调试信息(函数名，变量名等)
        - 参考了https://www.cnblogs.com/lvdongjie/p/8994092.html
        ```c++
        (gdb) l //列出原码
        1       #include <iostream>
        2       using namespace std;
        3   
        4       int fun(int n) {
        5               int sum = 0;
        6               for (int i = 1; i <= n; i++) sum += i;
        7               return sum;
        8       }
        9
        10      int main() {
        (gdb) l
        11              int x = 0, y = 0;
        12              cout << "x: " << x << "   y: " << y << endl;
        13              cout << "result[1-200]" << fun(200) << endl;
        14              for (int i = 0; i < 5; i++) {
        15                      x += 3;
        16                      y += 5;
        17              }
        18              cout << "x: " << x << "   y: " << y << endl;
        19      }
        (gdb) break 11 //断点
        Breakpoint 1 at 0x11b0: file test.cpp, line 11.
        (gdb) break fun 
        Breakpoint 2 at 0x1180: file test.cpp, line 5.
        (gdb) r //运行
        Starting program: /home/lvjx/study/DSA/LAB0/test
        [Thread debugging using libthread_db enabled]
        Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

        Breakpoint 1, main () at test.cpp:11
        11              int x = 0, y = 0;
        (gdb) s //step，单步执行
        12              cout << "x: " << x << "   y: " << y << endl;
        (gdb) s
        x: 0   y: 0
        13              cout << "result[1-200]" << fun(200) << endl;
        (gdb) watch y //检测y，y的值发生变化的时候停下
        Hardware watchpoint 3: y
        (gdb) info break
        Num     Type           Disp Enb Address            What
        1       breakpoint     keep y   0x00005555555551b0 in main() at test.cpp:11
        breakpoint already hit 1 time
        2       breakpoint     keep y   0x0000555555555180 in fun(int) at test.cpp:5
        3       hw watchpoint  keep y                      y
        (gdb) s

        Breakpoint 2, fun (n=200) at test.cpp:5
        5               int sum = 0;
        (gdb) s
        6               for (int i = 1; i <= n; i++) sum += i;
        (gdb) p sum
        $1 = 0
        (gdb) s
        7               return sum;
        (gdb) p sum
        $2 = 20100
        (gdb) n
        8       }
        (gdb) n
        result[1-200]20100
        main () at test.cpp:14
        14              for (int i = 0; i < 5; i++) {
        (gdb) c
        Continuing.

        Hardware watchpoint 3: y

        Old value = 0
        New value = 5
        main () at test.cpp:14
        14              for (int i = 0; i < 5; i++) {
        (gdb) p x
        $3 = 3
        (gdb) c
        Continuing.

        Hardware watchpoint 3: y

        Old value = 5
        New value = 10
        main () at test.cpp:14
        14              for (int i = 0; i < 5; i++) {
        (gdb) d 3 //删除检测信息
        (gdb) c //continue
        Continuing.
        x: 15   y: 25
        [Inferior 1 (process 3246) exited normally]
        (gdb) q //退出
        ```
    3. rand_input.cpp 中调用 srand(time(0)) 的作用
        - srand(): 初始化随机数发生器,需要传入一个种子seed,种子固定生成的随机数就是固定的
        - srand(time(0)): 把当前的时间作为seed传入，确保每次运行程序时生成的随机数都不相同
        - *参考了https://www.runoob.com/w3cnote/cpp-rand-srand.html*
    4. battle.cpp中每次调用system执行命令的功能
        ```c++
        //编译目标源文件并且生成指定名称的可执行文件
        system("g++ rand_input.cpp -o rand_input");
        system("g++ check_input.cpp -o check_input");
        system("g++ solution_1.cpp -o solution_1");
        system("g++ solution_2.cpp -o solution_2");
        //执行指定可执行文件,并且将标准输入和输出重定向到指定文件
        //'>'是指定输出文件,'<'是指定输入文件
        system("./rand_input > rand.in");//得到一个随机输入数据rand.in
        system("./check_input < rand.in");//检查生成的输入数据是否合法
        system("./solution_1 < rand.in > 1.out");//将rand.in作为输入运行solution_1,并将输出重定向到1.out
        system("./solution_2 < rand.in > 2.out")
        //比较1.out和2.out(不区分行末空格和文末换行)
        //返回值为0表示一样,为1表示存在差异,并输出差异
        system("diff 1.out 2.out");
        ```
    5. argv[0]的含义
        - 命令行中输入的程序名称或者该文件的路径，比如我输入./LAB0/test来执行test文件，那么argv[0]就是./LAB0/test

- **4.0节要求描述的算法思路**
    - 引入一个二维数组dp，dp[i][j]表示一个从(0,0)开始，大小为i*j的子数组的所有元素的和，这样，给定一个子数组后，就可以利用已知的4个子数组元素的和表示出该子数组的元素和，每次询问的复杂度就是O(1)，预处理的复杂度是O(mn)
    ```c++
    //计算dp[i][j] 类似容斥原理
    dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i][j];
    //计算sum
    sum = dp[X][Y] - dp[X][y - 1] - dp[x - 1][Y] + dp[x - 1][y - 1];
    ```

- **4.1节要求回答的问题**
    - 有明显优势
    ```s
    # n=2000 m=2000 q=100000
    ./solution_1 < test.in > test.out  40.42s user 0.02s system 99% cpu 40.441 total
    ./solution_2 < test.in > test.out  0.73s user 0.03s system 99% cpu 0.760 total
    ./solution_3 < test.in > test.out  0.28s user 0.02s system 99% cpu 0.297 total

    # n=1500 m=1500 q=100000
    ./solution_1 < test.in > test.out  24.88s user 0.01s system 99% cpu 24.893 total
    ./solution_2 < test.in > test.out  0.36s user 0.03s system 99% cpu 0.395 total
    ./solution_3 < test.in > test.out  0.17s user 0.02s system 99% cpu 0.193 total

    # n=1000 m=1000 q=100000
    ./solution_1 < test.in > test.out  9.57s user 0.00s system 99% cpu 9.568 total
    ./solution_2 < test.in > test.out  0.17s user 0.02s system 99% cpu 0.185 total
    ./solution_3 < test.in > test.out  0.10s user 0.01s system 99% cpu 0.110 total
    ```
    - 没有明显优势
    ```s
    # 500 500 100000
    ./solution_1 < test.in > test.out  2.25s user 0.00s system 99% cpu 2.247 total
    ./solution_2 < test.in > test.out  0.05s user 0.02s system 99% cpu 0.077 total
    ./solution_3 < test.in > test.out  0.06s user 0.00s system 99% cpu 0.056 total

    # 100 100 10000
    ./solution_1 < test.in > test.out  0.01s user 0.00s system 98% cpu 0.014 total
    ./solution_2 < test.in > test.out  0.01s user 0.00s system 95% cpu 0.005 total
    ./solution_3 < test.in > test.out  0.00s user 0.00s system 97% cpu 0.005 total

    # 2000 2000 100
    ./solution_1 < test.in > test.out  0.29s user 0.02s system 99% cpu 0.311 total
    ./solution_2 < test.in > test.out  0.25s user 0.00s system 99% cpu 0.251 total
    ./solution_3 < test.in > test.out  0.24s user 0.02s system 99% cpu 0.258 total
    ```

    - 测试条件满足以下条件时，solution3会有明显优势
        - q较大,>2*10^4
        - n较大,>q/10
        - n*m不能远大于q