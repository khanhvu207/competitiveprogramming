#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

#define pp pair<int,int>
using namespace std;
const int maxn = 101;
const int maxp = 30001;
int n,m,w[maxn],e[maxn],p[maxn],f[maxn][maxn];
pp trace[maxn][maxn];
map<int,int> mp;

vector<pp> lis;

void dfs(int i, int j)
{
    if (trace[i][j]!=pp(0,0)){
        dfs(trace[i][j].first,trace[i][j].second);
    }

//    printf("%d %d\n",mp[p[i]],j);
    lis.push_back(pp(mp[p[i]],j));
}
int main()
{
    freopen("CEDAR.INP","r",stdin);
    freopen("CEDAR.OUT","w",stdout);

    scanf("%d\n",&m);
    for (int i=1; i<=m; ++i){
        scanf("%d %d\n",&w[i],&e[i]);
    }
    scanf("%d\n",&n);
    for (int i=1; i<=n; ++i){
        scanf("%d ",&p[i]);
        mp[p[i]] = i;
        f[1][i] = 1;
    }

    sort(p+1,p+n+1);

    int ans = 0, tra_i,tra_j;
    for (int i=2; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            f[i][j] = 1;

            for (int ii=1; ii<i; ++ii){
                for (int jj=1; jj<=m; ++jj){
                    if (p[ii]+e[jj]<=p[i] && p[i]-w[j]>=p[ii] && f[ii][jj]+1>f[i][j]){
                        f[i][j] = f[ii][jj] + 1;
                        trace[i][j] = pp(ii,jj);
                    }
                }
            }

            if (ans < f[i][j]){
                ans = f[i][j];
                tra_i = i;
                tra_j = j;
            }
        }
    }

    printf("%d\n",ans);
    dfs(tra_i,tra_j);
    sort(lis.begin(),lis.end());
    for (int i=0; i<(int)lis.size(); ++i){
        printf("%d %d\n",lis[i].first,lis[i].second);
    }
    return 0;
}
