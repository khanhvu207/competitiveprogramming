#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
int sx, sy, tx, ty, n;
map<pair<int, int>, bool> mx;
map<pair<int, int>, int> d;
queue<pair<int, int> > q;
const int dx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8]={-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    freopen("king.inp", "r", stdin);
    freopen("king.out", "w", stdout);
    cin>>sx>>sy>>tx>>ty;
    cin>>n;
    for (int i=0, r, x, y; i<n; i++)
    {
        cin>>r>>x>>y;
        for (int j=x; j<=y; j++)
            mx[{r, j}]=1;
    }
    q.push({sx, sy});
    d[{sx, sy}]=0;
    while (!q.empty())
    {
        pair<int, int> t=q.front(); q.pop();
        for (int i=0; i<8; i++)
        {
            pair<int, int> td=t;
            td.first+=dx[i];
            td.second+=dy[i];
            if (mx.count(td)&&!d.count(td))
                q.push(td),
                d[td]=d[t]+1;
        }
    }
    if (!d.count({tx, ty}))
        cout<<-1;
    else
        cout<<d[{tx, ty}];
    return 0;
}
