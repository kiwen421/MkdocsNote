#include  <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int l, n, k, ans=0;
int f[N];

bool check(int x){
    int pre=f[1], cnt = k;
    for (int i=2; i<=n; i++){
        if (f[i] - pre > x){   //  两个路标的距离大于x，说明需要加入路标
            cnt--;   // 路标数量-1
            pre += x;   // 贪心做法，放置距离刚好是x,  并记录新位置
            i--;         // 当前路标还需要和pre再判断一次 
        } else pre = f[i];
        
        if (cnt < 0) return 0;
    }
    return 1;
}

int main(){
    cin >> l >> n >> k;
    for (int i=1; i<=n; i++) cin >> f[i];
    
    // 二分答案
    int L = 0,  R = f[n], mid;    // 由题意可知 不设路标的情况下，最大距离为f[n];
    while (L <= R){
        mid = L + ((R-L) >> 1);
        if (check(mid)){
            ans = mid;
            R = mid - 1;
        } else L = mid + 1;
    }
    cout << ans;
}