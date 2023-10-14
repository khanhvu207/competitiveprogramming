#define Link ""

#include <iostream>
#include <cstdio>

#define TASK "SINGER"

using namespace std;

const int Mod = 998244353;
const int maxn = 6420 + 10;
int n,d,t,f[maxn][maxn][2];

void Enter()
{
    cin >> n >> d >> t;
}

void Init()
{

}

int Add(int a, int b)
{
    a += b;
    if (a >= Mod)
        a -= Mod;
    return a;
}

void Solve()
{
    f[0][0][0] = 1;
    for (int i=1;i<d-1;++i)
        f[i][0][0] = f[i-1][0][0] * 2 % Mod;
    f[d-1][1][1] = 2;
    f[d-1][0][0] = (f[d-2][0][0] * 2 - f[d-1][1][1]) % Mod;
    for (int i=d;i<=n;++i) {
        for (int j=0;j<=t;++j)
            f[i][j][0] = Add(f[i][j][0],Add(f[i-1][j][0],f[i-1][j][1]));
        for (int j=1;j<=t;++j)
            f[i][j][1] = Add(f[i][j][1],f[i-1][j-1][1]);
        for (int j=1;j<=t;++j)
            f[i][j][1] = Add(f[i][j][1],Add(f[i-d+1][j-1][0],f[i-d+1][j-1][1]));
    }
    cout << Add(f[n][t][0],f[n][t][1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LHL
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
#else
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
#endif // LHL

    Enter();
    Init();
    Solve();
}
