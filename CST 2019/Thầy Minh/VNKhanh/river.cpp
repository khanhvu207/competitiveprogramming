#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int t, n, a[1015], b[1015], d[1015][1015];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("river.inp", "r", stdin);
	freopen("river.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int gcd, lcm=1, u, x, v, tmp;
		for (int i=1; i<=n; i++)
		{
			cin >> a[i] >> b[i];
			gcd=__gcd(lcm, a[i]+b[i]);
			lcm=(lcm*(a[i]+b[i]))/gcd;
		}
		for (int i=0; i<=n+1; i++)
			for (int j=0; j<=lcm; j++)
				d[i][j]=1e9;
		a[0]=a[n+1]=1;
		d[0][0]=0;
		heap.push(make_pair(0, 0));
		while (!heap.empty())
		{
			x=heap.top().first;
			u=heap.top().second;
			heap.pop();
			if (d[u][x%lcm]!=x) continue;
			for (v=max(0, u-5); v<=min(n+1, u+5); ++v)
                if ((v==0)||(v==n+1)||((x+1)%(a[v]+b[v])>0&&(x+1)%(a[v]+b[v])<=a[v]))
                {
                    tmp=(x+1)%lcm;
                    if (d[v][tmp]>x+1)
                    {
                        d[v][tmp]=x+1;
                        heap.push(make_pair(x+1, v));
                    }
                }	
		}
		int res=1e9;
		for (int i=0; i<=lcm; i++) 
			res=min(res, d[n+1][i]);
		if (res==1e9)
			cout << "NO\n";
		else
			cout << res << '\n';
	}
	return 0;
}