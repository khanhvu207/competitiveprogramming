#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>

#define ii pair<int,int>
using namespace std;
const int maxn = 1001;
int n,p,t,d[maxn];
vector<ii> adj[maxn];
priority_queue<ii, vector<ii>, greater<ii> > hp;
stringstream fs;
string str;
bool bacterials[maxn];

int main()
{
    freopen("VIKHUAN1.INP","r",stdin);
    freopen("VIKHUAN1.OUT","w",stdout);

    scanf("%d\n",&n);
    scanf("%d\n",&p);
    scanf("%d\n",&t);
    int u,v,c,ans=0,len;

    getline(cin,str);
    fs << str;
    while (!fs.eof()){
        fs >> u;
        bacterials[u] = true;
    }

    for (int i=1; i<n; ++i){
        scanf("%d %d %d\n",&u,&v,&c);
        adj[u].push_back(ii(v,c));
        adj[v].push_back(ii(u,c));
    }

    memset(d,-1,sizeof(d));
    d[p] = 0;
    hp.push(ii(0,p));

    while (!hp.empty()){
        c = hp.top().first;
        u = hp.top().second;
        hp.pop();

        if (c!=d[u]) continue;
        if (c>t) break;

        bacterials[u] = false;
        for (int i=0; i<(int)adj[u].size(); ++i){
            v = adj[u][i].first;
            len = adj[u][i].second;

            if (d[v]==-1 || d[u]+len<d[v]){
                d[v] = d[u] + len;
                hp.push(ii(d[v],v));
            }
        }
    }

    for (int i=1; i<=n; ++i)
        if (bacterials[i]) ++ans;
    printf("%d\n",ans);
    return 0;
}
