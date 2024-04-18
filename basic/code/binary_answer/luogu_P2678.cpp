#include  <bits/stdc++.h>

using namespace std;
const int N = 5e4 + 5;

int l, n, m, ans=0;
int f[N];

bool check(int x){    // 判定x为最短的最大跳跃距离是否符合规则
    int pre = 0, cnt = m;
    for (int i=1; i<=n; i++){
      if (f[i] - pre < x) cnt--;
      else pre = f[i];
      
      if (cnt < 0) return 0;
    }
    return 1;
}

int main(){
  cin >> l >> n >> m;
  for (int i=1; i<=n; i++) cin >> f[i];
  
  f[++n] = l; // 记录终点
  
  // 二分答案
  int L = 0,  R = l, mid;
  while (L <= R){
      mid = L + ((R - L) >> 1);
      if (check(mid)){       // 判断 mid 是否满足条件
        ans = mid;
        L = mid + 1;       // 如果mid 满足， 继续向右探测，判断[mid+1, R] 是否有更优的解
      } else R = mid - 1;    // 如果不满足，代表解在 [L, mid-1]之间
  }
  cout << ans;
}