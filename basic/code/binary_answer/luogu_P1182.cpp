#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;


int n, m, ans=0;
int f[N];

bool check(int x){
	int ans = 0, cnt = 0;
	for (int i = 1; i<=n; i++){
		ans += f[i];
		if (ans > x){   // 贪心做法，尽量拿最多
			++cnt;     // 累加段数
			if (cnt == m && ans > x) return 0;     // 特判断， 如果最后一段>x 代表该答案不可行
			ans = 0;
			i--;     
		} 
	}
	return 1;
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> f[i];
	
	// 二分答案
	int L = 0,  R= 1e9, mid;
	while (L <= R){
		mid = L + ((R-L) >> 1);
		if (check(mid)){
			ans = mid;
			R = mid -1;
		} else L  = mid +  1;
	}
	cout << ans;
	
}