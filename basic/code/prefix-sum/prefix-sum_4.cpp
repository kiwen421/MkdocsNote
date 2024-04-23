#include <bits/stdc++.h>

using namespace std;
const int N = 1005;

int n,m, x1, y_1, x2, y_2;
int f[N][N];   
int main(){
	cin >> n >> m;
	for (int i=1; i<=m; i++){
		cin >> x1 >> y_1 >> x2 >> y_2;
		f[x1][y_1] += 1;                  // 左上角
		f[x2+1][y_1] -= 1;             // 左下角
		f[x1][y_2+1] -= 1;            // 右上角
		f[x2+1][y_2+1] += 1;     //  右下角
	}
	
	// 前缀和处理
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			f[i][j] = f[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
		}
	}
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}
}