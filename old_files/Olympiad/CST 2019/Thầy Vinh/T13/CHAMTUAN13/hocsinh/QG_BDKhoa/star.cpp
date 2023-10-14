#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;

int n,m,b[15][15];
vector <ii> a;
bool flag,fre[20];
char c[15][15];

bool kt()
{
    int s[9]; s[7]=1e9;
    s[1] = b[2][2] + b[2][4] + b[2][6] + b[2][8];
    s[2] = b[4][2] + b[4][4] + b[4][6] + b[4][8];
    s[3] = b[1][5] + b[2][4] + b[3][3] + b[4][2];
    s[4] = b[1][5] + b[2][6] + b[3][7] + b[4][8];
    s[5] = b[5][5] + b[4][6] + b[3][7] + b[2][8];
    s[6] = b[5][5] + b[4][4] + b[3][3] + b[2][2];
    int dem=1;
    for (int i=1; i<=6; i++)
        if (s[i]==s[i+1]) dem++;
    if (dem==6) return true;
}

void sol(int i)
{
    if (i==a.size())
    {
        if (kt()) flag = true;
        if (flag)
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
                if (c[i][j]=='x') cout <<(char) (b[i][j]-1+'A');
                else cout <<  c[i][j];
            cout << '\n';
        }
        return;
    }

    for (int j=1; j<=12; j++)
        if (fre[j])
        {
            fre[j]= false;
            b[a[i].fi][a[i].se] = j;
            sol(i+1);
            fre[j] = true;
            if (flag) return;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("star.inp","r",stdin);
    freopen("star.out","w",stdout);
    n=5; m=9;
    memset(fre,true,sizeof(fre));
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            char t;
            cin >> t;c[i][j]=t;
            if ('A' <= t && t <='L')
            {
                b[i][j] = (int) t - (int) 'A' + 1;
                fre[b[i][j]] = false;
            }
            if (t=='x') a.push_back(ii(i,j));
        }
    flag = false;
    sol(0);
  //  if (!flag) cout << -1;
    return 0;
}
