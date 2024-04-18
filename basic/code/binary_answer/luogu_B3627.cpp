#include <bits/stdc++.h>

using namespace std;
const double  eps = 1e-7;

long long  n;
int main() {
	cin >> n;	
	
	// 二分答案
	double L = 0, R = 1e5;
	while (R - L > eps){
		double mid = (R  + L )/2;
		if (mid * mid *mid >= n) R  = mid;
		else L = mid;
	}
	if (L - int(L) - 0.9999999 > 0 ) cout << int(L+1);
	else cout << int(L);

}