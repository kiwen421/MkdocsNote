#include <bits/stdc++.h>

using namespace std;

int n, m, ans=-1e9;
int f[125][125];
int main(){
	cin >> n;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> f[i][j];
			f[i][j] = f[i-1][j] + f[i][j-1] + f[i][j] - f[i-1][j-1];     // 做二维前缀和
		}
	}
	
	// 枚举所有的可能信， x2,y2, x1,y1 
	for (int x2=1; x2<=n; x2++){
		for (int y2=1; y2<=n; y2++){
			for (int x1=1; x1<x2; x1++){
				for (int y_1 = 1; y_1<y2; y_1++){
					ans = max(ans,  f[x2][y2] - f[x1-1][y2] - f[x2][y_1-1] + f[x1-1][y_1-1]);  //求子矩阵 并更新
				}
			}
		}
	}
	cout << ans;
}