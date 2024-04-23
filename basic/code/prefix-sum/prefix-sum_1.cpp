#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int n, m, l, r;
int f[N];
int main() {
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> f[i];
		f[i] = f[i] + f[i-1];      // 前缀和预处理
	}
	cin >> m;
	for (int i=1; i<=m; i++){
		cin >> l >> r;
		cout << f[r] - f[l-1] << endl; // 求解   
	}
}