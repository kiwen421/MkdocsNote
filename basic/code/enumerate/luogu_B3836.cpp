#include <bits/stdc++.h>

using namespace std;


int x, y, z, n, m, ans=0;
int main() {
	cin >> x >>  y >> z >> n >> m; 
	
	for (int i=0; i<=m; i++){   // 枚举公鸡
		for (int j=0; j<=m; j++){   // 枚举母鸡
			for (int k=0; k<=m; k++){ // 枚举小鸡
				if (k%z == 0 && x*i + y*j + k/z == n && i + j + k == m){
					ans++;
				}
			}
		}
	}
	
	cout << ans;	
}