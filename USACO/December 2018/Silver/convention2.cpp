#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define fi first
#define se second
#define prev asdjkas
typedef pair<int, pair<int, int> > cows;
const int N = 100015;

int n;
cows c[N];
queue<cows> a;
priority_queue<cows, vector<cows>, greater<cows> > heap;

bool cmp(const cows &l, const cows &r)
{
	return l.se.fi < r.se.fi;
}

void addCows(int t)
{
	while (a.front().se.fi <= t && !a.empty())
		heap.push(a.front()), a.pop();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i].se.fi >> c[i].se.se;
		c[i].fi = i;
	}
	sort(c, c + n, cmp);
	for (int i = 0; i < n; ++i) a.push(c[i]);

	heap.push(a.front()); a.pop();
	while (a.front().se.fi == heap.top().se.fi) 
		heap.push(a.front()), a.pop();
	
	int prev = heap.top().se.fi;	
	int res = 0;
	while (!a.empty())
	{
		if (heap.empty()) //no cows are eating
		{
			addCows(a.front().se.fi);
			prev = heap.top().se.fi;
		}
		cows nxt = heap.top(); heap.pop();
		res = max(res, prev - nxt.se.fi);
		addCows(prev + nxt.se.se);
		prev += nxt.se.se;
	}
	cout << res;
}