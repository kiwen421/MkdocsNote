#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-5;

double w0, w, m;

int check(double x){
	double ans = 0;
	x+=1;
	for (int i=1; i<=m; i++){
		ans = ans + w / (pow(x, i));
	}
	return ans > w0;
}

int main(){
	cin >> w0 >> w >> m;
	// 二分答案
	double L = 0, R = 3, mid;
	while (R - L > eps){
		mid = (R + L) / 2;
		
		if (check(mid)) L = mid;
		else R = mid;
	}
	printf("%.1lf", L*100);
	
}