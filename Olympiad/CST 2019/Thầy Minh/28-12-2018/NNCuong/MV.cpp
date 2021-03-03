#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 200;
int n,k,m,s,t,a[maxn],na;
long long f[maxn][maxn],id;
string str;

void inday(int x, int len)
{
    while (len--){
        printf("%c",x+'0');
    }
}
int main()
{
    freopen("MV.INP","r",stdin);
    freopen("MV.OUT","w",stdout);

    scanf("%d %d %d\n",&n,&k,&m);
    f[n+1][k+1] = 1;
    for (int i=n; i>0; --i){
        for (int j=1; j<=k; ++j){
            for (int l=1; l<=m && i+l-1<=n; ++l){
                f[i][j] += f[i+l][j+1];
            }
        }
    }

    printf("%lld\n",f[1][1]);
    int sum;
    scanf("%d\n",&s);
    for (int i=1; i<=s; ++i){
        getline(cin,str);
        na = 0; id = 1; sum = 1;
        for (int i=0; i<(int)str.size(); ++i){
            if (!i || str[i]!=str[i-1]){ ++na; a[na]=0; }
            ++a[na];
        }

        for (int i=1; i<=na; ++i){
            if (i&1){ /// i la le => khoi thu i la 1
                for (int l=1; l<a[i]; ++l){
                    if (sum+l-1<=n) id += f[sum+l][i+1];
                }
            } else {
                for (int l=m; l>a[i]; --l){
                    if (sum+l-1<=n) id += f[sum+l][i+1];
                }
            }

            sum += a[i];
        }

        printf("%lld\n",id);
    }

    scanf("%d\n",&t);
    long long temp;
    for (int ii=1; ii<=t; ++ii){
        scanf("%lld ",&id);
        temp = 0; sum = 1;
        for (int i=1; i<=k; ++i){
            if (i&1){
                for (int l=1; l<=m; ++l){
                    if (sum+l-1>n) continue;
                    if (sum+l-1<=n && temp+f[sum+l][i+1]<id) temp += f[sum+l][i+1];
                    else {
                        inday(1,l);
                        sum += l;
                        break;
                    }
                }
            } else {
                for (int l=m; l>=1; --l){
                    if (sum+l-1>n) continue;
                    if (temp+f[sum+l][i+1]<id) temp += f[sum+l][i+1];
                    else {
                        inday(0,l);
                        sum += l;
                        break;
                    }
                }
            }
        }

        printf("\n");
    }
    return 0;
}
