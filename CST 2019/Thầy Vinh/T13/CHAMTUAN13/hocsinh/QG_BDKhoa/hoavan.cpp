#include <bits/stdc++.h>

using namespace std;

int n,m,b[105][105];
bool fre[105][105],flag;
char a[105][105];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int ux, int uy)
{
    for (int i=0; i<8; i++)
    {
        int vx = ux + dx[i];
        int vy = uy + dy[i];
        if (fre[vx][vy] && a[vx][vy]=='#')
        {
            if (b[vx][vy]==2)
            {
                fre[vx][vy] = false;
                dfs(vx,vy);
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (!flag) return;
    }
}

int main()
{
    freopen("hoavan.inp","r",stdin);
    freopen("hoavan.out","w",stdout);
    cin >> n >> m;
    for (int i=0; i<=n+1; i++)
        for (int j=0; j<=m+1; j++)
            a[i][j]='a';
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]=='#')
            for (int k=0; k<8; k++)
                if (a[i+dx[k]][j+dy[k]]=='#')
                    b[i][j]++;
    memset(fre,true,sizeof(fre));
    int kq=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]=='#' && fre[i][j])
            {
                fre[i][j] = false;
                flag = true;
                dfs(i,j);
                if (flag) kq++;
            }
    cout << kq;

    return 0;
}
