#include <iostream>
#include <cstdio>
using namespace std;

int v, e, s, m, g, t, aptr, bptr;
int len[115][115], ar[1015], br[1015];
bool duck[115];

struct SPlayer
{
	int curnode, nextnode, dist;
};

void init (SPlayer &X, bool flag)
{
	if (!flag)
	{
		X.curnode=ar[aptr];
		if (aptr+1<s)
			X.nextnode=ar[aptr+1];
		else
			X.nextnode=X.curnode;
		X.dist=0;
	} else
	{
		X.curnode=br[bptr];
		if (bptr+1<m)
			X.nextnode=br[bptr+1];
		else
			X.nextnode=X.curnode;
		X.dist=0;
	}
}

void nextMove (SPlayer &X, bool flag)
{
	if (!flag)
	{
		if (X.curnode==X.nextnode) return;
		++X.dist;
		if (X.dist==len[X.curnode][X.nextnode])
		{
			X.curnode=X.nextnode;
			++aptr;
			if (aptr+1<s)
				X.nextnode=ar[aptr+1];
			else
				X.nextnode=X.curnode;
			X.dist=0;
		}
	} else
	{
		if (X.curnode==X.nextnode) return;
		++X.dist;
		if (X.dist==len[X.curnode][X.nextnode])
		{
			X.curnode=X.nextnode;
			++bptr;
			if (bptr+1<m)
				X.nextnode=br[bptr+1];
			else
				X.nextnode=X.curnode;
			X.dist=0;
		}
	}
}

bool geoducks (SPlayer X)
{
	return (X.dist==0&&duck[X.curnode]);
}

bool canMeet (SPlayer A, SPlayer B, int _time)
{
	if (A.dist==0&&B.dist==0&&A.curnode==B.curnode) return true;
	if (A.curnode==B.nextnode&&A.nextnode==B.curnode&&A.dist<1&&B.dist<1
		&&(t-_time>=(len[A.curnode][A.nextnode]/2+(len[A.curnode][A.nextnode]&1)))) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("geoducks.inp", "r", stdin);
	freopen("geoducks.out", "w", stdout);
	cin >> v >> e >> s >> m >> g >> t;
	for (int i=0, u, v, c; i<e; i++)
		cin >> u >> v >> c,
		len[u][v]=c,
		len[v][u]=c;
	for (int i=0; i<s; i++)
		cin >> ar[i];
	for (int i=0; i<m; i++)
		cin >> br[i];
	for (int i=0, x; i<g; i++)
		cin >> x, 
		duck[x]=1;
	
	aptr=0, bptr=0;
	SPlayer A;
	SPlayer B;
	init(A, 0);
	init(B, 1);
	if (geoducks(A)||geoducks(B))
	{
		cout << "NO";
		return 0;
	}
	if (canMeet(A, B, 0))
	{
		cout << "YES";
		return 0;
	}
	for (int tick=1; tick<=t; ++tick)
	{
		if (geoducks(A)||geoducks(B))
		{
			cout << "NO";
			return 0;
		}
		if (canMeet(A, B, tick))
		{
			cout << "YES";
			return 0;
		}
		nextMove(A, 0);
		nextMove(B, 1);
		//cerr << tick << ' ' << A.curnode << ' ' << A.dist << '\n'; 
		//cerr << tick << ' ' << B.curnode << ' ' << B.dist << '\n';
		//cerr << '\n';
	}
	if (geoducks(A)||geoducks(B))
	{
		cout << "NO";
		return 0;
	}
	if (canMeet(A, B, t))
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}