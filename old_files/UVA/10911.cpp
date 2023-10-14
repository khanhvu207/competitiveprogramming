#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int n, C=0;
pair<double, double> a[20];
double dp[10][77777];

double dist (const pair<int, int> &l, const pair<int, int> &r)
{
    return sqrt((l.first-r.first)*(l.first-r.first)+(l.second-r.second)*(l.second-r.second));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    while (cin >> n)
    {
        if (n<1) return 0;
        for (int i=0; i<2*n; ++i)
        {
            string s;
            cin >> s >> a[i].first >> a[i].second;
        }
        for (int i=0; i<2*n-1; ++i)
            for (int j=i+1; j<2*n; ++j)
            {
                int mask=(1<<i);
                dp[1][mask|(1<<j)]=dist(a[i], a[j]);
            }
        for (int k=2; k<=n; ++k)
            for (int mask=0; mask<(1<<(2*n)); ++mask)
            {
                if (__builtin_popcount(mask)!=2*k) continue;
                dp[k][mask]=1000000000.0;
                for (int i=0; i<2*n-1; ++i)
                    for (int j=i+1; j<2*n; ++j)
                        if (mask&(1<<i)&&mask&(1<<j))
                        {
                            int tmask=mask;
                            tmask^=(1<<i);
                            tmask^=(1<<j);
                            dp[k][mask]=min(dp[k][mask], dp[k-1][tmask]+dist(a[i], a[j]));
                        }
            }
        cout << "Case " << ++C << ": " << fixed << setprecision(2) << dp[n][(1<<(2*n))-1] << '\n';
    }
}
