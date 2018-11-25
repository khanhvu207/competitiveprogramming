#include <iostream>
#include <cstring>
using namespace std;

string a, b;
int d, k, n;
long long dp[20][10][20][2][2][2];

long long rec (int cur, int pre, int bad, bool oka, bool okb, bool ok)
{
    if (dp[cur][pre][bad][oka][okb][ok]!=-1) return dp[cur][pre][bad][oka][okb][ok];
    if (cur==n)
        return (bad<=k)*1ll;
    long long cnt=0ll;
    for (int i=0; i<10; ++i)
        if ((oka||(i>=a[cur]-'0'))&&(okb||(i<=b[cur]-'0')))
            cnt+=rec(cur+1, i, bad+((abs(i-pre)<=d&&ok)?1:0), oka||(i>a[cur]-'0'), okb||(i<b[cur]-'0'), ok||(i>0));
    dp[cur][pre][bad][oka][okb][ok]=cnt;
    return cnt;
}

int main()
{
    cin >> a >> b >> d >> k;
    while ((int)a.size()<(int)b.size()) a='0'+a;
    while ((int)a.size()>(int)b.size()) b='0'+b;
    n=(int)a.size();
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0, 0, false, false, false);
}
