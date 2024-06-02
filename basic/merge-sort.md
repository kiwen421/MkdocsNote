## 定义

归并排序（[merge sort](https://en.wikipedia.org/wiki/Merge_sort)）是高效的基于比较的稳定排序算法。归并排序基于分治思想将数组分段排序后合并，时间复杂度在最优、最坏与平均情况下均为 $\Theta (n \log n)$，空间复杂度为 $\Theta (n)$。



## 过程

### 分治法实现分解数组

通过分治法，使用二分的方式，递归把一个数列分解成**长度不大于1**的子数列；已知长度为1时，数列本身就是有序的，然后在递归回溯的过程中，把两个有序的数组合并成一个有序数组，直到回溯完毕。


??? +note
    如果把以上分解过程理解成一颗二叉树的话，那么合并过程 就是二叉树的后序遍历。

### 合并

归并排序最核心的部分是合并（merge）过程：将两个有序的数列 `f[l, mid]` 和 `f[mid+1, r]` 合并为一个有序数组 `tmp`。

从左往右枚举 `f[i]` 和 `f[j]`，找出最小的值并放入数组 `tmp`里；如果`f[i]` 与`f[j]`相同的话， 则先把`f[i]`放入`tmp`里，保证其稳定性；重复上述过程直到 `f[l, mid]` 和 `f[mid+1, r]` 有一个找完时，将另一个数列剩下的元素放入 `tmp`。

#### 代码模版

===  "分治"
    ```cpp
    void mergeSort(int f[], int l, int r){  // 归并排序
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(f, l, mid);      // 递归左半区
        mergeSort(f, mid+1, r);		 // 递归右半区
        _merge(f, l, mid, r);
    }
    ```

=== "合并"
    ```cpp
    void _merge(int f[], int l, int mid, int r){   // 合并
        vector<int> tmp;
        int i = l, j = mid+1;
        while (i <= mid && j <= r){
            if (f[i] <=  f[j]) tmp.push_back(f[i++]);
            else tmp.push_back(f[j++]);
        }
        while (i <= mid) tmp.push_back(f[i++]);
        while (j <= r) tmp.push_back(f[j++]);
        int len = tmp.size();
        for (int i=0; i<len; i++) f[i+l] = tmp[i];
    }
    ```

=== "完整模版"
    ```cpp
    void _merge(int f[], int l, int mid, int r){   // 合并
        vector<int> tmp;
        int i = l, j = mid+1;
        while (i <= mid && j <= r){
            if (f[i] <=  f[j]) tmp.push_back(f[i++]);
            else tmp.push_back(f[j++]);
        }
        while (i <= mid) tmp.push_back(f[i++]);
        while (j <= r) tmp.push_back(f[j++]);
        int len = tmp.size();
        for (int i=0; i<len; i++) f[i+l] = tmp[i];
    }
    
    void mergeSort(int f[], int l, int r){  // 归并排序
        if (l >= r) return;
        int mid = (l + r) >> 1;
    
        mergeSort(f, l, mid);
        mergeSort(f, mid+1, r);
        _merge(f, l, mid, r); 
    }
    ```

## 逆序对

逆序对是 $i < j$ 且 $a_i > a_j$ 的有序数对 $(i, j)$。

排序后的数组无逆序对，归并排序的合并操作中，每次后段首元素被作为当前最小值取出时，前段**剩余元素个数之和**即是合并操作减少的逆序对数量；故归并排序计算逆序对数量的额外时间复杂度为 $\Theta (n \log n)$

### 代码模版
```cpp
long long ans = 0;  // 记录逆序对数量
void _merge(int f[], int l, int mid, int r){   // 合并
	vector<int> tmp;
	int i = l, j = mid+1;
	while (i <= mid && j <= r){
		if (f[i] <=  f[j]) tmp.push_back(f[i++]);   // 小于等于的 只让f[i++], 保证其稳定性
		else {
			ans = ans + (mid - i) + 1;   // 记录逆序对数量
			tmp.push_back(f[j++]);
		}
	}
	while (i <= mid) tmp.push_back(f[i++]);
	while (j <= r) tmp.push_back(f[j++]);
	int len = tmp.size();
	for (int i=0; i<len; i++) f[i+l] = tmp[i];
}

void mergeSort(int f[], int l, int r){  // 归并排序
	if (l >= r) return;
	int mid = (l + r) >> 1;
	
	mergeSort(f, l, mid);
	mergeSort(f, mid+1, r);
	
	_merge(f, l, mid, r);
}
```


## 题单

- [P1177 【模板】排序](https://www.luogu.com.cn/problem/P1177)

- [P1908 逆序对](https://www.luogu.com.cn/problem/P1908)
