/*
ID: khanhvu2
LANG: C++14
TASK: contact
*/
#include <bits/stdc++.h>
using namespace std;

int l, r, n, cnt[20][(1<<13)+1];
string ts, s="";

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("contact.in", "r", stdin);
  freopen("contact.out", "w", stdout);
  cin>>l>>r>>n;
  while (cin>>ts) {
    s+=ts;
  }
  int m=s.size();
  for (int i=0; i<m; ++i) {
    for (int len=l; len<=r; ++len) {
      if (i+len>m) break;
      int num=0;
      for (int j=i; j<i+len; ++j) {
        num=(num<<1)^(s[j]-'0');
      }
      ++cnt[len][num];
    }
  }
  vector<int> t;
  for (int len=l; len<=r; ++len) {
    for (int i=0; i<(1<<len); ++i) {
      t.push_back(cnt[len][i]);
    }
  }
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  for (int i=(int)t.size()-1; i>=max(0, (int)t.size()-n); --i) {
    if (!t[i]) break;
    cout<<t[i]<<'\n';
    int f=1;
    for (int len=l; len<=r; ++len) {
      for (int j=0; j<(1<<len); ++j) {
        if (cnt[len][j]!=t[i]) continue;
        int x=j;
        string tmp="";
        while (x) {
          tmp=(char)((x&1)+'0')+tmp;
          x>>=1;
        }
        while ((int)tmp.size()<len)
          tmp='0'+tmp;
        if (f==7) {
          cout<<'\n';
          f=1;
        }
        if (f>1) cout<< ' ';
        cout<<tmp;
        ++f;
      }
    }
    cout<<'\n';
  }
  return 0;
}
