author: StudyingFather, Backl1ght, countercurrent-time, Ir1d, greyqz, MicDZ, ouuan, renbaoshuo, Lixuannan

请确保您已经会普通莫队算法了。如果您还不会，请先阅读前面的 [普通莫队算法](./mo-algo.md)。

## 特点

普通莫队是不能带修改的。

我们可以强行让它可以修改，就像 DP 一样，可以强行加上一维 **时间维**, 表示这次操作的时间。

时间维表示经历的修改次数。

即把询问 $[l,r]$ 变成 $[l,r,\text{time}]$。

那么我们的坐标也可以在时间维上移动，即 $[l,r,\text{time}]$ 多了一维可以移动的方向，可以变成：

-   $[l-1,r,\text{time}]$
-   $[l+1,r,\text{time}]$
-   $[l,r-1,\text{time}]$
-   $[l,r+1,\text{time}]$
-   $[l,r,\text{time}-1]$
-   $[l,r,\text{time}+1]$

这样的转移也是 $O(1)$ 的，但是我们排序又多了一个关键字，再搞搞就行了。

可以用和普通莫队类似的方法排序转移，做到 $O(n^{5/3})$。

这一次我们排序的方式是以 $n^{2/3}$ 为一块，分成了 $n^{1/3}$ 块，第一关键字是左端点所在块，第二关键字是右端点所在块，第三关键字是时间。

???+ note "最优块长以及时间复杂度分析"
    我们设序列长为 $n$，$m$ 个询问，$t$ 个修改。
    
    带修莫队排序的第二关键字是右端点所在块编号，不同于普通莫队。
    
    想一想，如果不把右端点分块：
    
    -   乱序的右端点对于每个询问会移动 $n$ 次。
    -   有序的右端点会带来乱序的时间，每次询问会移动 $t$ 次。
    
    无论哪一种情况，带来的时间开销都无法接受。
    
    接下来分析时间复杂度。
    
    设块长为 $s$，则有 $\dfrac{n}{s}$ 个块。对于块 $i$ 和块 $j$，记有 $q_{i,j}$ 个询问的左端点位于块 $i$，右端点位于块 $j$。
    
    每「组」左右端点不换块的询问 $(i,j)$，端点每次移动 $O(s)$ 次，时间单调递增，$O(t)$。
    
    左右端点换块的时间忽略不计。
    
    表示一下就是：
    
    $$
    \begin{aligned}
    &\sum_{i=1}^{n/s}\sum_{j=i+1}^{n/s}(q_{i,j}\cdot s+t)\\
    =&ms+\left(\dfrac{n}{s}\right)^2t\\
    =&ms+\dfrac{n^2t}{s^2}
    \end{aligned}
    $$
    
    考虑求导求此式极小值。设 $f(s)=ms+\dfrac{n^2t}{s^2}$。那 $f'(s)=m-\dfrac{2n^2t}{s^3}=0$。
    
    得 $s=\sqrt[3]{\dfrac{2n^2t}{m}}=\dfrac{2^{1/3}n^{2/3}t^{1/3}}{m^{1/3}}=s_0$。
    
    也就是当块长取 $\dfrac{n^{2/3}t^{1/3}}{m^{1/3}}$ 时有最优时间复杂度 $O\left(n^{2/3}m^{2/3}t^{1/3}\right)$。
    
    常说的 $O\left(n^{5/3}\right)$ 便是把 $n,m,t$ 当做同数量级的时间复杂度。
    
    实际操作中还是推荐设定 $n^{2/3}$ 为块长。

## 例题

???+ note " 例题 [「国家集训队」数颜色/维护队列](https://www.luogu.com.cn/problem/P1903)"
    题目大意：给你一个序列，M 个操作，有两种操作：
    
    1.  修改序列上某一位的数字
    2.  询问区间 $[l,r]$ 中数字的种类数（多个相同的数字只算一个）

我们不难发现，如果不带操作 1（修改）的话，我们就能轻松用普通莫队解决。

但是题目还带单点修改，所以用 **带修改的莫队**。

### 过程

先考虑普通莫队的做法：

-   每次扩大区间时，每加入一个数字，则统计它已经出现的次数，如果加入前这种数字出现次数为 $0$，则说明这是一种新的数字，答案 $+1$。然后这种数字的出现次数 $+1$。
-   每次减小区间时，每删除一个数字，则统计它删除后的出现次数，如果删除后这种数字出现次数为 $0$，则说明这种数字已经从当前的区间内删光了，也就是当前区间减少了一种颜色，答案 $-1$。然后这种数字的出现次数 $-1$。

现在再来考虑修改：

-   单点修改，把某一位的数字修改掉。假如我们是从一个经历修改次数为 $i$ 的询问转移到一个经历修改次数为 $j$ 的询问上，且 $i<j$ 的话，我们就需要把第 $i+1$ 个到第 $j$ 个修改强行加上。
-   假如 $j<i$ 的话，则需要把第 $i$ 个到第 $j+1$ 个修改强行还原。

怎么强行加上一个修改呢？假设一个修改是修改第 $pos$ 个位置上的颜色，原本 $pos$ 上的颜色为 $a$，修改后颜色为 $b$，还假设当前莫队的区间扩展到了 $[l,r]$。

-   加上这个修改：我们首先判断 $pos$ 是否在区间 $[l,r]$ 内。如果是的话，我们等于是从区间中删掉颜色 $a$，加上颜色 $b$，并且当前颜色序列的第 $pos$ 项的颜色改成 $b$。如果不在区间 $[l,r]$ 内的话，我们就直接修改当前颜色序列的第 $pos$ 项为 $b$。
-   还原这个修改：等于加上一个修改第 $pos$ 项、把颜色 $b$ 改成颜色 $a$ 的修改。

因此这道题就这样用带修改莫队轻松解决啦！

### 实现

??? 参考代码
    ```cpp
    --8<-- "docs/misc/code/modifiable-mo-algo/modifiable-mo-algo_1.cpp"
    ```