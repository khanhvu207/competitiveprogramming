#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair <int,int>

using namespace std;

ii a[200000];
int n,m,p[200000];

int findroot(int u)
{
  while (p[u]>0) u=p[u];
  return u;
}

void unite(int x, int y)
{
  int s=p[x]+p[y];
  if (p[x]<p[y]) p[x]=s,p[y]=x;
  else p[x]=y,p[y]=s;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("dsf.inp","r",stdin);
    freopen("dsf.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
      int u,v;
      cin >> a[i].fi >> a[i].se;
    }
    for (int i=1; i<=n; i++) p[i]=-1;

    int kq=n;
    for (int i=1; i<=m; i++)
    {
      int u,v;
      u=findroot(a[i].fi);
      v=findroot(a[i].se);
      if (kq == 1) 
	  {
		  cout << 1 << '\n';
		  continue;
	  }
	  if (u!=v)
      {
          kq--;
          unite(u,v);
      }
      cout << kq << '\n';
    }
    return 0;
}
