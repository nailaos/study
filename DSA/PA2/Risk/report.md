### Risk

- ##### 算法实现的思路:
  - 总体上是Queap的思路，但是使用数组实现，并且做了一些优化。
  - **开始思路**
    - 用一个窗口去维护，具体就是一个数组加上起始位置，因为结束位置肯定是知道的，所以并不需要，每次先更新窗口的开始位置，这个直接更新就可以，因为题目中已经限制那个是单调不下降数列，也就意味着窗口的开始位置单调不下降，这个操作只需要O(1)的时间复杂度，接着会插入一个新的值，相应的窗口也要发生变化，这个在最坏情况下会有O(k)的复杂度，k位当前窗口的大小。最后就是查找答案，答案是显然的，就是开始位置的那个元素，因为这个窗口是一个单调不上升数列。
  - **改进思路**
    - 上面的做法思路很简单，但是发现很多时候会做无意义的计算，比如之前有一个维护好的窗口是[9, 8, 8, 7, 7, 7, 7]，然后插入新的值的时候，如果插入的值比最大的还要大，那岂不是要把这个窗口每个都更新一遍(假设窗口的开始位置并没有发生改变)，这样会耗费大量时间，而且做的是无用功，因为更新之后的窗口里面是一个值在重复，所以就想到这种情况下就可以更新窗口的开始位置了，因为之前的信息已经是没有用的。但是这样并不能直接避免这类问题，比如这个窗口[10, 8, 8, 7, 7, 7, 7]，如果新插入一个9的话，还是要做大量的更改，而且窗口中存在大量的9。
    - 可以发现问题的根源在于在这个**窗口中存在很多相同的值**，导致每次做了大量的无用修改，于是想到一个解决的办法，窗口中只存储值，然后用另一个数组去记录位置(不是窗口的位置，准确来说是天数)。比如对于之前的[10, 8, 8, 7, 7, 7, 7]，我就可以用两个数组去表示，一个[10, 8, 7]，一个是[5, 8, 12] (为什么不是从1开始，可以看num的说明)，后者记录的是当前值的最后一个在窗口中所处的位置(后面详细说明)。同时需要两个变量去记录开始位置和窗口大小，然后每次都会更新开始位置和窗口大小。下面用代码来说明。
    ```c++
    //window是维护的窗口，days就是每天的确诊人数，num中记录window中元素对应的天数，start和len对应开始位置和窗口大小
    start = binarySearch0(num, start, len, day);//更新start
    if (days[i - 1] >= window[start]) {
      start = len = 0;//当前元素比窗口中最大的元素都大，说明可以开始维护一个新的数组了
    } else {
      len = binarySearch2(window, start, len, days[i - 1]);//那些比当前需要插入的值小的数都是无用的，所以直接更新窗口大小
    }
    window[len] = days[i - 1];//新插入的值始终位于数组的最后一位
    num[len] = i;//窗口以后一个对应的天数当然是持续到当天的
    ans[i] = window[satrt];//答案肯定是窗口中最大的那个，也就是开始的那个
    ```
    - 关于num的详细说明，可以这么理解，num中相邻的两个数之差代表窗口那个位置对应元素的重复次数，但是为何不直接就是那个呢？主要是考虑到更新这个窗口开始位置的问题，num中存的就是这个值可以使用的天数范围，只要你向前查找到第k天，那就可以根据这个来更新窗口的开始位置，为什么呢，比如一个num[j]对应的数比k小，那就意味着这个是第k天之前的信息，你自然是用不到了，所以每次二分查找，找到第一个大于等于所要查找的那个最早的天数。
    - 感觉是不知道怎么去清晰的表述我的想法，简单来看就是把之前的那个窗口压缩一下，然后对应的操作就会发生一些改变，但是算法的不变性和正确性都是没有发生改变的。
  - 解决了这个问题之后，后面的就很轻易了，先排序，然后每次查找直接二分查找。
- ##### 遇到的问题:
  - 使用了cin和cout，导致超时
    - 改为scanf和printf
  - 数据溢出问题
    - 使用unsigned int以及先判断然后相减
- ##### 时间复杂度: O((n+T)log(n))
  - 得到每天的最大确诊病例数的过程：操作次数位于n到2n，所以为O(n)
  - 排序：nlog(n)
  - 查询：Tlog(n)
- ##### 空间复杂度: O(n)
  - 3个数组：3n
