#include <iostream>
#include <cstdio>
#define fort(i,a,b) for(int i=a;i<=b;++i)
#define N 55
#define M 20
using namespace std;

int n,m,vy[N],mch[N];
int c[N][M];
char s[N][M],ch;

bool dfs(int x)
{
    fort(y,1,m) if (!vy[y] && c[x][y]){
        vy[y] = 1;
        if (mch[y] == 0 || dfs(mch[y]))
            return mch[y] = x, 1;
    }
    return 0;
}
int kuhn()
{
    int Count = 0;
    fort(x,1,n){
        Count += dfs(x);
        fort(y,1,m) vy[y] = 0;
    }
    return Count;
}
int main()
{
    freopen("BIT.inp","r",stdin);
    freopen("BIT.out","w",stdout);
    scanf("%d",&n); m = 16;
    fort(i,1,n) fort(j,1,16){
        scanf(" %c",&ch);
        c[i][j] = ch-'0';
        s[i][j] = ch;
    }
    int match = kuhn(), ans=0;
    fort(i,1,n) {
        int tmp = 0;
        s[i][0] = '0';
        fort(j,1,m) if (s[i][j] == '1' && s[i][j-1] == '0') tmp += 1;
        ans += tmp;
    }
    fort(j,1,m) {
        int tmp = 0;
        s[0][j] = '0';
        fort(i,1,n) if (s[i][j] == '1' && s[i-1][j] == '0') tmp += 1;
        ans += tmp;
    }
    cout << min (ans, match);
}
