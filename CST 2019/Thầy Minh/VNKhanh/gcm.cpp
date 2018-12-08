#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a, b, n, p[4444], best=2e9, resA, resB;
long long c[444], d[444];
vector<int> prime;
vector<pair<int, int> > dG, dL;
set<int> divisors;
map<int, int> cnt;

inline int _gcd(int a, int b)
{
    if (a%b==0) return b;
    else return _gcd(b%a, a);
}

void sieve(int x)
{
    for (int i=2; i<=x; ++i) p[i]=i;
    for (int i=2; i<=sqrt(x); ++i)
        if (p[i]==i)
            for (int j=2; j<=x/i; ++j)
                p[i*j]=i;
    for (int i=2; i<=x; ++i)
        if (p[i]==i) prime.push_back(i);
}

long long fastpow(long long base, long long expo)
{
    if (!expo) return 1ll;
    long long t=fastpow(base, expo/2);
    t=t*t;
    if (expo&1) return base*t;
        else return t;
}

void rec(int i, long long A, long long B)
{
    if (i==n)
    {
        if (B-A<best && B>=A)
            best=B-A,
            resA=A,
            resB=B;
        return;
    }
    rec(i+1, A*c[i], B*d[i]);
    rec(i+1, A*d[i], B*c[i]);
}

void Solve()
{
    sieve(1000);
    int GCD=_gcd(a, b);
    int ta=a, tb=b;
    for (int i=0; i<(int)prime.size() && prime[i]<=sqrt(ta); ++i)
    {
        int _cnt=0;
        while (ta%prime[i]==0)
        {
            ta/=prime[i];
            ++_cnt;
        }
        divisors.insert(prime[i]);
        cnt[prime[i]]+=_cnt;
    }
    if (ta>1)
    {
        divisors.insert(ta);
        ++cnt[ta];
    }
    for (int i=0; i<(int)prime.size() && prime[i]<=sqrt(tb); ++i)
    {
        int _cnt=0;
        while (tb%prime[i]==0)
        {
            tb/=prime[i];
            ++_cnt;
        }
        divisors.insert(prime[i]);
        cnt[prime[i]]+=_cnt;
    }
    if (tb>1)
    {
        divisors.insert(tb);
        ++cnt[tb];
    }
    for (int i=0; i<(int)prime.size() && prime[i]<=sqrt(GCD); ++i)
    {
        int _cnt=0;
        while (GCD%prime[i]==0)
        {
            GCD/=prime[i];
            ++_cnt;
        }
        dG.push_back(pair<int, int>(prime[i], _cnt));
        cnt[prime[i]]-=_cnt;
        if (cnt[prime[i]]<1) divisors.erase(prime[i]);
    }
    if (GCD>1)
    {
        --cnt[ta];
        if (cnt[ta]<1) divisors.erase(ta);
        dG.push_back(pair<int, int>(GCD, 1));
    }
    for (set<int>::iterator it=divisors.begin(); it!=divisors.end(); ++it)
        dL.push_back(pair<int, int>(*it, cnt[*it]));

    int x=(int)dG.size();
    sort(dG.begin(), dG.end());
    sort(dL.begin(), dL.end());
    for (int i=0; i<(int)dL.size(); ++i)
        if (i>=x)
            dG.push_back(pair<int, int>(dL[i].first, 0));
    n=(int)dL.size();
    for (int i=0; i<n; ++i)
        c[i]=fastpow(dG[i].first, dG[i].second),
        d[i]=fastpow(dL[i].first, dL[i].second);

    //for (int i=0; i<n; ++i)
    //    cerr << dL[i].first << ' ';
    rec(0, 1ll, 1ll);
    cout << resA << ' ' << resB << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("gcm.inp", "r", stdin);
    freopen("gcm.out", "w", stdout);
    cin >> a >> b;
    Solve();
}
