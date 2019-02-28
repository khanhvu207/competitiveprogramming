#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m;
ll t,b[10015],d[10015],f[10015];
bool vis[10015];
vector<pii> g[10015];
vector<int> a[10015],p[10015];
priority_queue<pii,vector<pii>,greater<pii> > q;

void dfs(int u, int p=-1) {
  f[u]=b[u];
  for (int v:a[u])
    if (v!=p) {
      dfs(v,u);
      f[u]+=f[v];
    }
}

int main() {
  freopen("shortcut.in","r",stdin);
  freopen("shortcut.out","w",stdout);
  cin>>n>>m>>t;
  for (int i=1;i<=n;++i)
    cin>>b[i];
  for (int i=0,u,v,c;i<m;++i) {
    cin>>u>>v>>c;
    g[u].push_back(make_pair(v,c));
    g[v].push_back(make_pair(u,c));
  }
  for (int i=1;i<=n;++i) d[i]=1e9;
  d[1]=0;
  q.push(pii(d[1],1));
  while (!q.empty()) {
    int u=q.top().second;
    int cost=q.top().first;
    q.pop();
    if (cost>d[u]) continue;
    vis[u]=true;
    for (pii i:g[u]) {
        int v=i.first;
        int L=i.second;
        if (d[u]+L==d[v])
          p[v].push_back(u);
        else if (!vis[v]&&d[u]+L<d[v]) {
          d[v]=d[u]+L;
          p[v].clear();
          p[v].push_back(u);
          q.push(pii(d[v],v));
        }
    }
  }
  for (int i=2;i<=n;++i) {
    sort(p[i].begin(),p[i].end());
    a[p[i][0]].push_back(i);
  }
  ll sum=0ll;
  for (int i=1;i<=n;++i)
    sum+=d[i]*b[i]*1ll;
  dfs(1);
  ll x=1e18;
  for (int i=2;i<=n;++i)
    x=min(x,sum-d[i]*f[i]+t*f[i]);
  cout<<max(0ll,sum-x);
}
