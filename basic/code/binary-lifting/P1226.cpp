#include <bits/stdc++.h>

using namespace std;
int a, b, p;

long long  _pow(int n, int k){
	long long  ans = 1;
	long long  tmp = n;
	while (k){
		if (k & 1) ans = ans * tmp % p;     
		tmp = tmp * tmp % p;
		k >>= 1;
	}
	
	return ans;
}

int main(){
	cin >> a >> b >> p;
	printf("%d^%d mod %d=%lld", a, b, p, _pow(a, b));
	
	
}