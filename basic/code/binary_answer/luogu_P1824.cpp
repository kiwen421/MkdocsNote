#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int n, c, _max=0, ans;
int f[N];

bool check(int x){
	int cnt = c - 1, pre = f[1]; 
	for (int i=2; i<=n; i++){
		if (f[i] - pre >= x){    // 如果间隔大于等于x 代表可以放置牛
			cnt--;    // 牛的数量 -1
			pre = f[i];   // 记录此时放置牛的位置
		} 
		if (cnt <= 0) return 1;     // 代表牛放置完了，满足条件
	}
	return 0;
}


int main() {
	cin >> n >> c;
	for (int i=1; i<=n; i++){
		cin >> f[i];
		_max = max(_max, f[i]);
	}
	sort(f+1, f+n+1);
	
	// 二分答案
	int L = 0,  R = _max, mid;
	while (L <= R){
		mid = L + ((R-L)>>1);
		if (check(mid)){
			L  = mid + 1;
			ans = mid;
		} else R  = mid - 1;
		
	}
	cout <<  ans;
}