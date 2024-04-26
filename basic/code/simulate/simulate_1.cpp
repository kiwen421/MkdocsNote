#include <bits/stdc++.h>

using namespace std;

int k;
int gold=1;   // 每次收到的金币
int ans = 0;   // 总金币
int cnt = 1;   // 记录每次发金币的段
int main() {
	cin >> k;
	for (int i=1; i<=k; i++){
		ans += gold;
		cnt--;
		if (cnt <= 0){
			gold++;     
			cnt = gold;   // 循环的次数 == 要发的金币数量
		}
	}
	cout << ans;

}