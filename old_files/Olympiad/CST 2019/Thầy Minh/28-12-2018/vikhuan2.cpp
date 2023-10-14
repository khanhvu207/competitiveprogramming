#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>

#define ii pair<int,int>
using namespace std;
const int maxn = 1001;
int n,p,d[maxn],nbac;
vector<ii> adj[maxn];
priority_queue<ii, vector<ii>, greater<ii> > hp;
stringstream fs;
string str;
bool bacterials[maxn],visited[maxn];


int dijkstra(int t)
{
    int u,v,c,len,temp=0;
    memset(d,-1,sizeof(d));
    d[p] = 0;

    while (!hp.empty()) hp.pop();
    hp.push(ii(0,p));

    while (!hp.empty()){
        c = hp.top().first;
        u = hp.top().second;
        hp.pop();

        if (c!=d[u]) continue;
        if (c>t) break;
        if (bacterials[u]) ++temp;
        for (int i=0; i<(int)adj[u].size(); ++i){
            v = adj[u][i].first;
            len = adj[u][i].second;

            if (d[v]==-1 || d[u]+len<d[v]){
                d[v] = d[u] + len;
                hp.push(ii(d[v],v));
            }
        }
    }

    return temp;
}
int main()
{
    freopen("VIKHUAN2.INP","r",stdin);
    freopen("VIKHUAN2.OUT","w",stdout);

    scanf("%d\n",&n);
    scanf("%d\n",&p);
    int u,v,c,ans=0;

    getline(cin,str);
    fs << str;
    while (!fs.eof()){
        fs >> u;
        bacterials[u] = true;
        ++nbac;
    }

    for (int i=1; i<n; ++i){
        scanf("%d %d %d\n",&u,&v,&c);
        adj[u].push_back(ii(v,c));
        adj[v].push_back(ii(u,c));
    }

    int inf=0,suf=30000000,mid;
    while (inf<=suf){
        mid = (inf+suf)/2;
        if (dijkstra(mid)>nbac/2){
            ans = mid;
            suf = mid-1;
        } else inf = mid + 1;
    }
    printf("%d\n",ans);
    return 0;
}
