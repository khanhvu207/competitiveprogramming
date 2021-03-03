#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
#define x first
#define y second
typedef pair<int, int> island;
typedef pair<double, pair<double, int> > SNode;
const double eps=1e-9;

int n;
island a[6555];
double d;
map<double, double> t;
map<pair<double, int>, double> V;
map<pair<double, int>, bool> vst;
priority_queue<SNode, vector<SNode>, greater<SNode> > q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("samac.inp", "r", stdin);
    freopen("samac.out", "w", stdout);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].x >> a[i].y;
    cin >> d;
    cin >> a[n].y;
    a[n].x=1e9+1;
    ++n;
    for (int i=0; i<n; ++i)
    {
        double x=abs(a[i].y-d);
        V[{x, i}]=x;
        q.push({V[{x, i}], {x, i}});
    }
    while (!q.empty())
    {
        double vol=q.top().x;
        double dist=q.top().y.x;
        int u=q.top().y.y;
        q.pop();
        //cerr << fixed << setprecision(3) << vol << ' ' << V[{dist, u}] << ' ' << vol-V[{dist, u}] << '\n';
        if (vol>V[{dist, u}]) continue;
        vst[{dist, u}]=1;
        if (u==n-1) t[dist]=vol;
        if (u==n-1) break;
        for (int i=0; i<n; ++i)
        {
            if (i==u||(a[i].y-a[u].y<-eps)) continue;
            double tdist=((i!=n-1)?sqrt((double)(a[u].x-a[i].x)*(a[u].x-a[i].x)+(double)(a[u].y-a[i].y)*(a[u].y-a[i].y)):abs(a[i].y-a[u].y));
            if (!vst.count({tdist+dist, i})&&(!V.count({tdist+dist, i})||max(vol, tdist)<V[{tdist+dist, i}]))
            {
                V[{tdist+dist, i}]=max(vol, tdist);
                q.push({V[{tdist+dist, i}], {tdist+dist, i}});
            }
        }
    }
    double res_vol=1000000000000000000.0;
    double res_dist=1000000000000000000.0;
    for (map<double, double>::iterator it=t.begin(); it!=t.end(); ++it)
    {
        if ((it->second)-res_vol<=eps)
        {
            if ((it->second)==res_vol)
                res_dist=min(res_dist, it->first);
            else
                res_vol=it->second,
                res_dist=it->first;
        }
    }
    cout << fixed << setprecision(3) << res_vol << '\n' << res_dist;
    return 0;
}
