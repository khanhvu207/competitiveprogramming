#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, t, ex, ey;
int maze[115][115];
string cmd;
bool vst[115][115][4][15];
int dp[115][115][4][15];
const int dx[4]={-1, 0, 1, 0};
const int dy[4]={0, 1, 0, -1};

bool solve (int x, int y, int face, int k)
{
    if (dp[x][y][face][k]!=-1) return dp[x][y][face][k];
    if (x==ex&&y==ey) return 1;
    vst[x][y][face][k]=1;
    if (cmd[k]=='L')
    {
        face=(face+3)%4;
        if (!vst[x][y][face][(k+1)%t])
            if (solve(x, y, face, (k+1)%t))
            {
                dp[x][y][face][(k+1)%t]=1;
                return true;
            }
    } else if (cmd[k]=='R')
    {
        face=(face+1)%4;
        if (!vst[x][y][face][(k+1)%t])
            if (solve(x, y, face, (k+1)%t))
            {
                dp[x][y][face][(k+1)%t]=1;
                return true;
            }
    } else
    {
        int xx=x;
        int yy=y;
        x=x+dx[face];
        y=y+dy[face];
        if (x<0||x>=n||y<0||y>=m||maze[x][y]==-1)
        {
            if (!vst[xx][yy][face][(k+1)%t])
                if (solve(xx, yy, face, (k+1)%t))
                {
                    dp[xx][yy][face][(k+1)%t]=1;
                    return true;
                }
        } else
        {
            if (!vst[x][y][face][(k+1)%t])
                if (solve(x, y, face, (k+1)%t))
                {
                    dp[x][y][face][(k+1)%t]=1;
                    return true;
                }
        }
    }
    return false;
}

int main()
{
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    cin >> n >> m >> t;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            char x; cin >> x;
            if (x=='E')
            {
                ex=i;
                ey=j;
                maze[i][j]=1;
                continue;
            }
            maze[i][j]=(x=='#'?-1:0);
        }
    cin >> cmd;
    int res=0;
    memset(dp, -1, sizeof dp);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (maze[i][j]!=-1)
            {
                memset(vst, 0, sizeof vst);
                if (solve(i, j, 0, 0))
                {
                    //cerr << i+1 << ' ' << j+1 << '\n';
                    ++res;
                }
            }
    if (res==n*m)
        cout << "YES\n";
    else
        cout << res;
    return 0;
}
