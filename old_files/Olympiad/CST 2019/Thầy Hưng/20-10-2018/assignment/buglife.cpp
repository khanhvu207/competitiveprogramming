#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int t, n, m, color[2015];
vector<int> g[2015];
bool chk(int u)
{
	queue<int> q;
	q.push(u);
	color[u]=0;
	while (!q.empty())
	{
		int k=q.front(); q.pop();
		for (int v:g[k])
			if (color[v]<0)
			{
				color[v]=1^color[k];
				q.push(v);
			}
			else if (color[v]==color[k]) return false;
	}	
	return true;
}
int main()
{
	cin>>t;
	int C=0;
	while (t--)
	{
		cin>>n>>m;
		for (int i=1; i<=n; i++) g[i].clear();
		for (int i=0, u, v; i<m; i++)
			cin>>u>>v,
			g[u].push_back(v),
			g[v].push_back(u);
		memset(color, -1, sizeof color);
		bool bipartite=1;
		for (int i=1; i<=n; i++)
			if (color[i]<0) bipartite&=chk(i);
		cout<<"Scenario #"<<++C<<":\n";
		cout<<(bipartite?"No suspicious bugs found!\n":"Suspicious bugs found!\n");
	}
	return 0;
}