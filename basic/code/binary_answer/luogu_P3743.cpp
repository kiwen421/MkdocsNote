#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-4; // 定精度

struct node { 
	double a, b;
} f[N];
int n, p;

bool check(double x){
	double t = x * p;  // 总共充电宝可以充的电

	for (int i=1; i<=n; i++){
		if (f[i].a * x  > f[i].b){     // 如果消耗的电 大于 总电
			t = t - (f[i].a * x  - f[i].b);   // 使用充电宝的电
		} 
		if (t < 0) return 0;   // 如果充电宝的电，不够用代表条件不满足
	}
	return 1;
}


int main() {
	cin >> n >> p;
	double t = 0;
	double c = 0;
	for (int i=1; i<=n; i++){
		cin >> f[i].a >> f[i].b;
		t += f[i].a;
		c = max(c, f[i].b);
	}
	
	// 特判 -1 
	if (t <= p){
		cout << -1 << endl; return 0;
	}
	
	// 二分答案
	double L = 0,   R = 1e10, mid;
	while (R - L > eps){
		mid = (R + L) / 2;
		if (check(mid)){  
			L = mid;
		} else  R = mid;
	}
	cout << L;
}