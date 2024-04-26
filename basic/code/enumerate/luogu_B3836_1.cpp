#include <bits/stdc++.h>

using namespace std;


int x, y, z, n, m, ans=0;
int main() {
	cin >> x >>  y >> z >> n >> m; 
	
	for (int i=0; i<=m; i++){   // 枚举公鸡
		for (int j=0; j<=m-i; j++){   // 枚举母鸡
			int k = m - i - j;
			if (k % z == 0 && (i * x + j * y + k/z) == n) ans++;
		}
	}
	
	cout << ans;	
}