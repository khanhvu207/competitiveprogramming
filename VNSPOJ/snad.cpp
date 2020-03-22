#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

int t, n, k;
string a, b;
ull dp[25][555][2][2];
ull l, r;

string convert (ull X)
{
    string res="";
    while (X) res=(char)(X%10ull+48ull)+res, X/=10ull;
    return res;
}

bool chk (ull x, ull s)
{
    return ((ull)l<=x*s&&x*s<=(ull)r);
}

long long solve (int cur, int sum, bool oka, bool okb, ull num)
{
    if (dp[cur][sum][oka][okb]!=-1ull) return dp[cur][sum][oka][okb];
    if (cur==n)
        return (sum==k&&chk(num, sum))*1ull;
    long long cnt=0ll;
    for (int i=0; i<10; ++i)
        if ((oka||i>=a[cur]-'0')&&(okb||i<=b[cur]-'0'))
            cnt+=solve(cur+1, sum+i, oka||(i>a[cur]-'0'), okb||(i<b[cur]-'0'), num*10ull+i*1ull);
    dp[cur][sum][oka][okb]=cnt;
    return cnt;
}

long long calc (ull L, ull R)
{
    long long res=0;
    for (ull sum=1; sum<=min(R, 200ull); ++sum)
    {
        k=sum;
        a=convert((ull)((double)L/(sum*1.0)));
        b=convert((ull)((double)R/(sum*1.0)));
        while((int)a.size()<(int)b.size()) a='0'+a;
        while((int)a.size()>(int)b.size()) b='0'+b;
        n=(int)a.size();
        memset(dp, -1ull, sizeof dp);
        res+=solve(0, 0, false, false, 0ull);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cout << calc(l, r) << '\n';
    }
}
