本页面将介绍二分答案的使用。



### 定义

对可能的答案区间，使用二分枚举答案， 不断缩小范围，最终确定答案，一般用来求解满足某种条件的最大值或者最小值（最优解问题）



### 思路

给定条件$f(x)$ , 求满足条件的最小值,  $1 \le x \le 10^9$？

1. 首先可以确定的是 答案区间在$[1, 10^9]$之间， 满足单调性， 并且答案区间内有很多可行性解。

2. 二分答案区间，判断$mid$ 是否是可行性解，如果是，那么最优解应该出现在$[L, mid]$区间内， 更新记录$mid$； 否则最优解应该出现$[mid+1, R]$区间内。

3. 重复2操作，直到枚举所有的可能性答案。

???+ note "总结"

	1. 答案区间有边界，且满足单调性;
	2. 二分枚举答案区间，判断$f(mid)$是否可行， 将**求最优解问题**提转换为**判断可行性解问题**;
	3. 不断的执行2操作，找到最左或者最右的可行性解，即最优解。
	4. 二分答案最关键的不是在于枚举答案，而在于判断可行性解， 即`check`函数如何写，这个需要仔细设计。



### 代码模版

```cpp
bool check(int x){
  
  // 判断x是否是可行性解
}
// 二分答案 最小值
int binary_answer(int L, int R){
  int ret;
  int mid;
  while (L <= R){
    mid = L + (R-L)>>1;
    if (check(mid)){   // 判断是否是可行性解
      ret = mid;     // 更新记录最小值
      R = mid - 1;
    } else L = mid + 1;
  }  
  return ret;
}

// 二分答案 最大值
int binary_answer(int L, int R){
  int ret;
  int mid;
  while (L <= R){
    mid = L + (R-L)>>1;
    if (check(mid)){   // 判断是否满足条件
      ret = mid;     // 更新记录最大值
      L = mid + 1;
    } else R = mid - 1;
  }  
  return ret;
}


// 实数二分模版
double binary_answer(double L, double R){
  const double eps = 1e-7; // 10的-7次方
  double mid;
  while (R - L > eps){
    mid = (L+R)/2;
    if (check(mid)){ L = mid;  
    } else R = mid;
  }  
  return mid;
}
```



???+ note  "[Luogu P1873 砍树](https://www.luogu.com.cn/problem/P1873)"
    伐木工人米尔科需要砍倒 $M$ 米长的木材。这是一个对米尔科来说很容易的工作，因为他有一个漂亮的新伐木机，可以像野火一样砍倒森林。不过，米尔科只被允许砍倒单行树木。
    

    米尔科的伐木机工作过程如下：米尔科设置一个高度参数 $H$（米），伐木机升起一个巨大的锯片到高度 $H$，并锯掉所有的树比 $H$ 高的部分（当然，树木不高于 $H$ 米的部分保持不变）。米尔科就得到树木被锯下的部分。
    
    例如，如果一行树的高度分别为 $20,~15,~10,~17$，米尔科把锯片升到 $15$ 米的高度，切割后树木剩下的高度将是 $15,~15,~10,~15$，而米尔科将从第 $1$ 棵树得到 $5$ 米木材，从第 $4$ 棵树得到 $2$ 米木材，共 $7$ 米木材。
    
    米尔科非常关注生态保护，所以他不会砍掉过多的木材。这正是他尽可能高地设定伐木机锯片的原因。你的任务是帮助米尔科找到伐木机锯片的最大的整数高度 $H$，使得他能得到木材至少为 $M$ 米。即，如果再升高 $1$ 米锯片，则他将得不到 $M$ 米木材。
    
    ??? note "解题思路"
    	通过题意可知，伐木机可能的最大高度为其中最高树木的高度,设为x，我们可以在 $0$ 到 $x$ 中枚举答案，但是这种朴素写法肯定拿不到满分，因为从 $0$ 枚举到 $x$ 太耗时间。我们可以在 $[0, x]$ 的区间上进行二分作为答案，然后检查各个答案的可行性（一般使用贪心法）。**这就是二分答案。**
    
    ??? note  "参考代码"
    	```cpp
    	--8<-- "docs/basic/code/binary_answer/luogu_P1873.cpp"
    	```



???+ note "[luogo P2678 NOIP2015 提高组 跳石头](https://www.luogu.com.cn/problem/P2678)"
    一年一度的“跳石头”比赛又要开始了！
    
    这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间，有 $N$ 块岩石（不含起点和终点的岩石）。在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。
    
    为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。由于预算限制，组委会至多从起点和终点之间移走 $M$​ 块岩石（不能移走起点和终点的岩石）。
    
    第一行包含三个整数 $L,N,M$，分别表示起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数。保证 $L \geq 1$ 且 $N \geq M \geq 0$。
    
    ??? note "解题思路"
        通过题意可知， 最短跳跃距离最长距离可能是$L$, 即答案在$[0, L]$区间内，我们使用二分法，枚举答案区间即可。 需要注意的是，判断答案是否可行`check`函数应该怎么写？
        
        枚举方法：
        
    	  1. 从起点的下一块岩石 $next$ 开始枚举, 设 $pre$ 为0，当作起点的距离；$cnt=M$ 记录能移走的岩石数量。
     
    	  2. 如果 $next - pre \ge mid$ 则符合规则，更新岩石块 $pre=next$； 否则不满足条件, 更新移动数量$cnt++$（此时不能更新岩石块，不更新代表把当前岩石给移走了）。
    	    
    	  3. 待枚举完之后，判断$cnt \le m$ 即可。
    
    ??? note "参考代码"
        ```cpp
        --8<-- "docs/basic/code/binary_answer/luogu_P2678.cpp"
        ```



???+ note "[P3853 路标设置](https://www.luogu.com.cn/problem/P3853)"
    B 市和 T 市之间有一条长长的高速公路，这条公路的某些地方设有路标，但是大家都感觉路标设得太少了，相邻两个路标之间往往隔着相当长的一段距离。为了便于研究这个问题，我们把公路上相邻路标的最大距离定义为该公路的“空旷指数”。
    
    现在政府决定在公路上增设一些路标，使得公路的“空旷指数”最小。他们请求你设计一个程序计算能达到的最小值是多少。请注意，公路的起点和终点保证已设有路标，公路的长度为整数，并且原有路标和新设路标都必须距起点整数个单位距离。
    
    第 $1$ 行包括三个数 $L,N,K$，分别表示公路的长度，原有路标的数量，以及最多可增设的路标数量。
    
    第 $2$ 行包括递增排列的 $N$ 个整数，分别表示原有的 $N$ 个路标的位置。路标的位置用距起点的距离表示，且一定位于区间 $[0,L]$ 内。
    
    ??? note "题解"
        做法同上， 枚举答案区间$[0, L]$。
    
    ??? note "参考代码"
        ```cpp
        --8<-- "docs/basic/code/binary_answer/luogu_P3853.cpp"
        ```



### 题单

- [洛谷 P1873  砍树](https://www.luogu.com.cn/problem/P1873)

- [洛谷 P2678 跳石头](https://www.luogu.com.cn/problem/P2678)

- [洛谷 P3853 路标设置](https://www.luogu.com.cn/problem/P3853)

- [洛谷 P2440 木材加工](https://www.luogu.com.cn/problem/P2440)
???note "参考代码"
    ```cpp
    --8<-- "docs/basic/code/binary_answer/luogu_P2440.cpp"
    ```

- [洛谷 P1182 数列分段II](https://www.luogu.com.cn/problem/P1182)
???note "参考代码"
    ```cpp
    --8<-- "docs/basic/code/binary_answer/luogu_P1182.cpp"
    ```

- [洛谷 B3627 立方根](https://www.luogu.com.cn/problem/B3627)
???note "参考代码"
    ```cpp
    --8<-- "docs/basic/code/binary_answer/luogu_B3627.cpp"
    ```

- [洛谷 P1163 银行贷款](https://www.luogu.com.cn/problem/P1163)
???note "参考代码"
    ```cpp
    --8<-- "docs/basic/code/binary_answer/luogu_P1163.cpp"
    ```

- [洛谷 P3743 小鸟的设备](https://www.luogu.com.cn/problem/P3743)
???note "参考代码"
    ```cpp
    --8<-- "docs/basic/code/binary_answer/luogu_P3743.cpp"
    ```

- [洛谷 P1824 进击的奶牛](https://www.luogu.com.cn/problem/P1824)
???note "参考代码"
    ```cpp
    --8<-- "docs/basic/code/binary_answer/luogu_P1824.cpp"
    ```

- [洛谷 P1314 聪明的质检员](https://www.luogu.com.cn/problem/P1314)