#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int n, k, _max=-1, ans=0;
int f[N];

bool check(int x){
	int cnt=0;
	for (int i=1; i<=n; i++){
		if (f[i] >= x) cnt = cnt + f[i] / x;       // 累加切的段数
	}
	return cnt >= k;   // 判断
}


int main() {
	cin >> n >> k;
	
	for (int i=1; i<=n; i++){
		cin >> f[i];
		_max = max(f[i], _max);
	}
	
	// 二分答案
	int L = 1, R = _max, mid;
	while (L <= R){
		mid = L + ((R-L) >> 1);
		if (check(mid)){
			ans = mid;
			L = mid + 1;
		}  else R = mid-1;
	}
	
	cout << ans;
}