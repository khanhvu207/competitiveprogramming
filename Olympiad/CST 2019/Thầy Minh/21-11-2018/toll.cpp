#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, k, C=0, prevv[1000];
char s, t;
long long d[1000];
bool vst[1000];
vector<int> g[1000];
priority_queue<pair<long long, char>, vector<pair<long long, char> >, greater<pair<long long, char> > > q;

long long cost (long long x)
{
    long long l=x+1, r=1e15, res=0;
    while (l<=r)
    {
        long long m=(l+r)>>1;
        long long tcost=m-(m/20)-(m%20!=0);
        if (tcost>=x) r=m-1, res=m;
            else l=m+1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("toll.inp", "r", stdin);
    freopen("toll.out", "w", stdout);
    while (cin >> n)
    {
        if (n<0) return 0;
        for (int i=0; i<500; ++i)
            g[i].clear();
        for (int i=0; i<500; ++i) vst[i]=0;
        for (int i=0; i<n; ++i)
        {
            char u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin >> k >> s >> t;
        for (int i=0; i<500; ++i) d[i]=1e15;
        d[t]=('a'<=t&&t<='z'?(k+1):cost(k));
        q.push({d[t], t});
        prevv[t]=-1;
        while (!q.empty())
        {
            int sum=q.top().first;
            int u=q.top().second;
            q.pop();
            if (sum<d[u]) continue;
            vst[u]=1;
            for (int i=0; i<(int)g[u].size(); ++i)
            {
                int v=g[u][i];
                char cv=(char)v;
                int newsum=('a'<=cv&&cv<='z'?(sum+1):cost(sum));
                if (!vst[v]&&newsum<d[v])
                {
                    d[v]=newsum;
                    q.push({d[v], v});
                    prevv[v]=u;
                }
            }
        }
        cout << "#" << ++C << '\n';
        cout << d[s] << '\n';
        cout << s;
        s=prevv[s];
        while (prevv[s]!=-1)
        {
            cout << '-' << s;
            s=prevv[s];
        }
        cout << '-' << t;
        cout << '\n';
    }
    return 0;
}
