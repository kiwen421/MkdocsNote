#include <bits/stdc++.h>

using namespace std;
const int N = 5e6+5;

int n, p, x, y, z, ans = 100;
int f[N];
int main(){
	cin >> n >> p;
	for (int i=1; i<=n; i++) scanf("%d", f+i);
	
	for (int i=n; i>=1; i--) f[i] = f[i] - f[i-1];  //转化为差分数组
	
	for (int i=1; i<=p; i++){
		scanf("%d %d %d", &x, &y, &z);
		f[x] += z;        //  加分开始的点
		f[y+1] -= z;    //  结束加分的点
	}
	
	for (int i=1; i<=n; i++){
		f[i] =f[i] + f[i-1];   // 做前缀和还原
		ans = min(ans, f[i]);   
	}
	
	cout << ans;
}