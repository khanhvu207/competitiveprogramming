#define Link ""

#include <iostream>
#include <cstdio>
#include <vector>

#define TASK "VECTOR"

using namespace std;

const int maxval = 1e7 + 10;
const int maxn = 5e2 + 10;
int m,p[maxn],n,q[maxn],pre[maxval],cnt1[maxval],cnt2[maxval],memD[maxval];
vector <int> D,W,L;

void Enter()
{
    cin >> m;
    for (int i=1;i<=m;++i)
        cin >> p[i];
    cin >> n;
    for (int i=1;i<=n;++i)
        cin >> q[i];
}

void Init()
{
    pre[1] = 1;
    for (int i=1;i<maxval;++i)
        if (pre[i] == 1)
            for (int j=i+i;j<maxval;j+=i)
                pre[j] = i;
    for (int i=1;i<=m;++i)
        for (int j=p[i];j!=1;j=pre[j])
            ++cnt1[j/pre[j]];
    for (int i=1;i<=n;++i)
        for (int j=q[i];j!=1;j=pre[j])
            ++cnt2[j/pre[j]];
}

void SolD()
{
    int s = 1;
    for (int i=2;i<maxval;++i) {
        for (;memD[i]>0;--memD[i])
            if (1ll * s * i >= maxval) {
                D.push_back(s);
                s = i;
            }
            else
                s *= i;
    }
    D.push_back(s);
}

void SolW()
{
    int s = 1;
    for (int i=2;i<maxval;++i) {
        cnt2[i] /= 2;
        for (;cnt2[i]>0;--cnt2[i]) {
            ++cnt1[i];
            if (1ll * s * i >= maxval) {
                W.push_back(s);
                s = i;
            }
            else
                s *= i;
        }
    }
    W.push_back(s);
}

void SolL()
{
    int s = 1;
    for (int i=2;i<maxval;++i) {
        cnt1[i] /= 2;
        for (;cnt1[i]>0;--cnt1[i])
            if (1ll * s * i >= maxval) {
                L.push_back(s);
                s = i;
            }
            else
                s *= i;
    }
    L.push_back(s);
}

void Solve()
{
    for (int i=2;i<maxval;++i) {
        if (cnt2[i] % 2 == 1) {
            ++cnt2[i];
            ++memD[i];
        }
        if ((cnt2[i] / 2 + cnt1[i]) % 2 == 1) {
            cnt2[i] += 2;
            memD[i] += 2;
        }
    }
    SolD();
    SolW();
    SolL();
    cout << D.size() + W.size() + L.size() << '\n';
    for (int s : D)
        cout << s << " D\n";
    for (int s : W)
        cout << s << " W\n";
    for (int s : L)
        cout << s << " L\n";
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
