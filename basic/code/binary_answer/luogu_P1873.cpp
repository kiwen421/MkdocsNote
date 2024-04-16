#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int f[N];
int n, m,  _max=0;

bool check(int k) {  // 检查可行性，k 为锯片高度
	long long sum = 0;
	for (int i = 1; i <= n; i++){
	if (f[i] > k)  sum += (long long)(f[i] - k);     // 累加树木高度
	}
	return sum >= m;               
}

int binary_answer(int L, int R){
	int ret = -1;
	int mid;
	while (L <= R) {       
		mid = L + (R-L) >> 1;  
		if (check(mid)) {    // 判断可行性
			ret = mid;
			L = mid + 1;
		}	 else R = mid - 1;
	}
    	return ret;  
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		_max = max(f[i], _max); // 可行性答案的最大高度
	}
	cout << binary_answer(0, _max);
	return 0;
}