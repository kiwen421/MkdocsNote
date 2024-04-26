#include <bits/stdc++.h>

using namespace std;

int x, y, z, n, m, ans=0;
int main() {
	cin >> x >>  y >> z >> n >> m; 
	
	for (int i=0; i<=m; i++){   // 枚举公鸡
		for (int k=0; k<=m-i; k+=z){   // 枚举小鸡
			int j = m - i - k;
			if (i * x + j * y + k/z== n) ans++;
		}
	}
	
	cout << ans;	
}