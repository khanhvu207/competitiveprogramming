#define Link ""

#include <iostream>
#include <cstdio>
#include <algorithm>

#define TASK "TIGERSUGAR"

using namespace std;

const int maxn = 1e5 + 10;
int n,x[maxn*2],y[maxn*2],idx[maxn*2],idy[maxn*2],resX,resY,bestx[maxn],besty[maxn];

void Enter()
{
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> x[i*2] >> y[i*2] >> x[i*2+1] >> y[i*2+1];
        if (x[i*2] > x[i*2+1])
            swap(x[i*2],x[i*2+1]);
        if (y[i*2] > y[i*2+1])
            swap(y[i*2],y[i*2+1]);
    }
}

void Init()
{
    for (int i=0;i<2*n;++i)
        idx[i] = i;
    for (int i=0;i<2*n;++i)
        idy[i] = i;
    sort(idx,idx+2*n,
         [] (int i, int j)
         {
             return x[i] < x[j];
         });
    sort(idy,idy+2*n,
         [] (int i, int j)
         {
             return y[i] < y[j];
         });
}

int ABS(int x)
{
    return x < 0 ? -x : x;
}

long long Sol(int x[], int idx[], int &resX, int bestx[])
{
    long long res = 0;
    resX = x[idx[n]];
    for (int i=0;i<n;++i) {
        if (resX < x[i*2])
            bestx[i] = x[i*2];
        else
            if (x[i*2] <= resX && resX <= x[i*2+1])
                bestx[i] = resX;
            else
                bestx[i] = x[i*2+1];
        res += ABS(resX - bestx[i]);
    }
    return res;
}

void Solve()
{
    cout << Sol(x,idx,resX,bestx) + Sol(y,idy,resY,besty) << '\n';
    cout << resX << ' ' << resY << '\n';
    for (int i=0;i<n;++i)
        cout << bestx[i] << ' ' << besty[i] << '\n';
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
