/*
ID: khanhvu2
LANG: C++14
TASK: stamps
*/
#include <bits/stdc++.h>
using namespace std;

int k, n, v[50], maxv;
int f[2000001];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("stamps.in", "r", stdin);
  freopen("stamps.out", "w", stdout);
  cin>>k>>n;
  for (int i=0; i<n; ++i) {
    cin>>v[i];
    f[v[i]]=1;
    maxv=max(maxv, v[i]);
  }
  sort(v, v+n);
  int i=1;
  while (true) {
    if (f[i]!=1) f[i]=2e6+1;
    for (int j=0; j<n&&v[j]<=i; ++j)
      f[i]=min(f[i], f[i-v[j]]+1);
    if (f[i]>k) {
      cout<<i-1<<'\n';
      break;
    }
    ++i;
  }
  return 0;
}
