/*
ID: khanhvu2
LANG: C++14
TASK: humble
*/
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll n, k, p[100], h[100001];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("humble.in", "r", stdin);
  freopen("humble.out", "w", stdout);
  cin>>n>>k;
  for (int i=0; i<n; ++i) {
    cin>>p[i];
  }
  h[0]=1;
  for (int i=1; i<=k; ++i) {
    ll num=INT_MAX;
    for (int j=0; j<n; ++j) {
      int t=upper_bound(h, h+i, h[i-1]/p[j])-h;
      t-=(t>=i);
      num=min(num, h[t]*p[j]);
    }
    h[i]=num;
  }
  cout<<h[k]<<'\n';
  return 0;
}
