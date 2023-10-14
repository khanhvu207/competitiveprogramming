#define Link ""

#include <iostream>
#include <cstdio>
#include <vector>

#define TASK "WEDDING"

using namespace std;

const int maxn = 2e6 + 10;
int k,Mod,p[maxn],s[maxn],t[maxn],Div[maxn];

void Enter()
{
    cin >> k >> Mod;
    for (int i=0;i<k;++i)
        cin >> p[i];
}

int Pow(int x, int k)
{
    if (x == 0)
        return 0;
    if (k == 0)
        return 1;
    int t = Pow(x,k/2);
    t = 1ll * t * t % Mod;
    if (k % 2)
        t = 1ll * t * x % Mod;
    return t;
}

void Init()
{
    for (int x=0;x<Mod;++x)
        Div[x] = Pow(x,Mod-2);
}

bool Try(int m, int n)
{
    for (int i=0;i<m;++i)
        s[i] = -1;
    for (int j=0;j<n;++j)
        t[j] = -1;
    for (int i=0;i<m;++i) {
        bool fl = 1;
        for (int j=0;j<n;++j)
            if (p[i*n+j] != 0) {
                fl = 0;
                break;
            }
        if (fl)
            s[i] = 0;
    }
    for (int j=0;j<n;++j) {
        bool fl = 1;
        for (int i=0;i<m;++i)
            if (p[i*n+j] != 0) {
                fl = 0;
                break;
            }
        if (fl)
            t[j] = 0;
    }
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            if (p[i*n+j] == 0 && s[i] != 0 && t[j] != 0)
                    return 0;
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            if (p[i*n+j] != 0)
                if (s[i] != -1 && t[j] != -1) {
                    if (1ll * s[i] * t[j] % Mod != p[i*n+j])
                        return 0;
                }
                else
                    if (s[i] == -1 && t[j] == -1) {
                        s[i] = 1;
                        t[j] = p[i*n+j];
                    }
                    else
                        if (s[i] == -1)
                            s[i] = 1ll * p[i*n+j] * Div[t[j]] % Mod;
                        else
                            t[j] = 1ll * p[i*n+j] * Div[s[i]] % Mod;
    cout << "YES";
    cout << '\n' << m;
    for (int i=0;i<m;++i)
        cout << ' ' << s[i];
    cout << '\n' << n;
    for (int j=0;j<n;++j)
        cout << ' ' << t[j];
    return 1;
}

void Solve()
{
    for (int i=2;i<k;++i)
        if (k % i == 0)
            if (Try(i,k/i))
                return;
    cout << "NO";
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
