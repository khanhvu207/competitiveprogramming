#include <iostream>
using namespace std;

int n, m, r[10015], p[10015];
int root (int u)
{
	while (u!=p[u]) p[u]=p[p[u]], u=p[u];
	return u;
}
void joint (int u, int v)
{
	u=root(u);
	v=root(v);
	if (r[u]>r[v])
		r[u]+=r[v], p[v]=u;
	else
		r[v]+=r[u], p[u]=v;
}
int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++) 
		r[i]=1, p[i]=i;
	for (int i=0, u, v; i<m; i++)
	{
		cin >> u >> v;
		if (root(u)==root(v))
		{
			cout << "NO";
			return 0;
		}
		joint(u, v);
	}
	cout << "YES";
	return 0;
}