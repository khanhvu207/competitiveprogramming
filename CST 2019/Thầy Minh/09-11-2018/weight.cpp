#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

const double eps=1e-6;
int c, d, k, sum=0;
vector<int> coin, p;
double wt[2015], dp[115][100015];

double payback (int a)
{
    double s=0.0;
    for (int i=d-1; i>=0&&a>0; i--)
        if (a>=coin[i])
        {
            int q=a/coin[i];
            s+=q*wt[coin[i]]*1.0;
            a-=q*coin[i];
        }
    return s;
}

double solve (int cur, int remain)
{
    if (dp[cur][remain]>eps) return dp[cur][remain];
    if (cur==k)
    {
        if (remain>0)
            return 1000000000.0;
        else
            return payback(-1*remain);
    }
    double res=1000000000.0;
    res=min(res, solve(cur+1, remain-p[cur]));
    res=min(res, solve(cur+1, remain)+wt[p[cur]]);
    dp[cur][remain]=res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("weight.inp", "r", stdin);
    freopen("weight.out", "w", stdout);
    cin >> c >> d >> k;
    for (int i=0; i<d; i++)
    {
        int val; double w;
        cin >> val >> w;
        coin.push_back(val);
        wt[val]=w;
    }
    for (int i=0, id; i<k; i++)
        cin >> id,
        p.push_back(coin[id-1]),
        sum+=coin[id-1];
    sort(coin.begin(), coin.end());
    if (sum<c)
    {
        cout << "too poor";
        return 0;
    }
    for (int i=0; i<=110; i++)
        for (int j=0; j<=c; j++)
            dp[i][j]=-1000.0;
    double res=solve(0, c);
    cout << fixed << setprecision(2) << res << '\n';
    
    return 0;
}
