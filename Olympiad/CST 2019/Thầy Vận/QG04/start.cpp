#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
vector<pair<int, int> > t;

bool chk (int k)
{
    while (!q.empty()) q.pop();
    for (int i=0; i<n; i++)
        q.push(t[i]);
    int machine=k;
    int last_idle=-1;
    while (!q.empty())
    {
        int l=q.top().first;
        int r=q.top().second;
        q.pop();
        if (l==last_idle)
        {
            if (machine>1) machine--;
            else
            {
                if (l==r) return false;
                q.push({l+1, r});
            }
        } else
        {
            last_idle=l;
            machine=k;
        }
    }
    return true;
}

int main()
{
    freopen("start.inp", "r", stdin);
    freopen("start.out", "w", stdout);
    cin>>n;
    for (int i=0, x, y; i<n; i++)
        cin>>x>>y,
        t.push_back(make_pair(x, y));
    sort(t.begin(), t.end());
    int l=0, r=n, res;
    while (l<=r)
    {
        int m=(l+r)>>1;
        if (chk(m)) r=m-1, res=m;
            else l=m+1;
    }
    cout<<res;
    return 0;
}
