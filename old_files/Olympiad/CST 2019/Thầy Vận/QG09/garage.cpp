#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, m, slot[4111];
long long cost[111], w[2111];
queue<int> q;
priority_queue<int, vector<int>, greater<int> > heap;

void Input()
{
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> cost[i];
    for (int i=1; i<=m; ++i)
        cin >> w[i];
}

void Solve()
{
    long long profit=0;
    for (int i=1; i<=n; ++i) heap.push(i);
    for (int i=0, c; i<2*m; ++i)
    {
        cin >> c;
        if (c>0) q.push(c);
        else
        {
            c=-c;
            heap.push(slot[c]);
        }
        while (!heap.empty() && !q.empty())
        {
            slot[q.front()]=heap.top();
            profit+=w[q.front()]*cost[heap.top()];
            //cerr << q.front() << ' ' << heap.top() << '\n';
            q.pop(); heap.pop();
        }
    }
    cout << profit;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("garage.inp", "r", stdin);
    freopen("garage.out", "w", stdout);
    Input();
    Solve();
}
