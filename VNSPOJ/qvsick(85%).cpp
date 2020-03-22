#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

typedef unsigned long long ull;

ull pow2[65], pow3[45], pow5[30], pow7[25], dproduct;
ull l, r;
map<pair<pair<int, ull>, pair<bool, pair<bool, bool> > >, ull> dp;

int n, k2, k3, k5, k7;
string a, b;

bool chk (int exp2, int exp3, int exp5, int exp7)
{
    ull t=pow2[exp2]*pow3[exp3]*pow5[exp5]*pow7[exp7];
    return t<=sqrt(r);
}

string convert (ull x)
{
    string res="";
    while (x) res=(char)(x%10ull+48ull)+res, x/=10ull;
    return res;
}

ull solve (int cur, ull d, bool oka, bool okb, bool ok)
{
    if (dp.count({{cur, d}, {oka, {okb, ok}}})) return dp[{{cur, d}, {oka, {okb, ok}}}];
    if (cur==n)
        return (d==1ull)*1ull;
    ull cnt=0ll;
    for (ull i=(ok?1ull:0ull); i<10ull; ++i)
        if ((oka||i>=a[cur]-'0')&&(okb||i<=b[cur]-'0')&&(i<1||d%i==0ull))
            cnt+=solve(cur+1, (i==0ull?d:d/i), oka||(i>a[cur]-'0'), okb||(i<b[cur]-'0'), ok||i>0);
    dp[{{cur, d}, {oka, {okb, ok}}}]=cnt;
    return cnt;
}

int main()
{
    cin >> l >> r;

    pow2[0]=1ull;
    for (int i=1; i<=60; ++i) pow2[i]=pow2[i-1]*2ull;
    pow3[0]=1ull;
    for (int i=1; i<=38; ++i) pow3[i]=pow3[i-1]*3ull;
    pow5[0]=1ull;
    for (int i=1; i<=26; ++i) pow5[i]=pow5[i-1]*5ull;
    pow7[0]=1ull;
    for (int i=1; i<=22; ++i) pow7[i]=pow7[i-1]*7ull;

    ull res=0ull;
    for (int exp2=0; exp2<=60; ++exp2)
    {
        if (!chk(exp2, 0, 0, 0)) break;
        for (int exp3=0; exp3<=38; ++exp3)
        {
            if (!chk(exp2, exp3, 0, 0)) break;
            for (int exp5=0; exp5<=26; ++exp5)
            {
                if (!chk(exp2, exp3, exp5, 0)) break;
                for (int exp7=0; exp7<=22; ++exp7)
                {
                    if (!chk(exp2, exp3, exp5, exp7)) break;
                    dproduct=pow2[exp2]*pow3[exp3]*pow5[exp5]*pow7[exp7];
                    a=convert(ceil((double)l/dproduct*1.0));
                    b=convert(floor((double)r/dproduct*1.0));
                    while ((int)a.size()<(int)b.size()) a='0'+a;
                    while ((int)a.size()>(int)b.size()) b='0'+b;
                    n=(int)a.size();
                    dp.clear();
                    res+=solve(0, dproduct, false, false, false);
                }
            }
        }
    }
    cout << res;
}

///98765432100 999990000099999909
///119654315835
