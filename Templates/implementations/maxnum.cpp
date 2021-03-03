#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

//-------math----------

#define spr(x) ((x)*(x))
#define PI acos(-1)

//-------pair-----------

#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mkp make_pair

//------for-------------

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i =(a); i >= (b); i--)
#define FORV(i,a,b) for(int i = (a); i < (b); i++)
#define FORVD(i,a,b) for(int i = (a); i > (b); i--)

//-----num-------------

#define ll long long
#define inf long(1e9)
#define infll 1000000000000000000
/*---------------------*/

const int maxn = 1000;

ll Pow2[100];

string ToAmHai(ll x)
{
    string a = "";
    do
    {
        a = (char)((abs(x) % 2) + '0') + a;
        if (x % 2 == 0) x = -x / 2; else x = (1 - x) / 2;
    }
    while(x != 0);
    return a;
}

ll ToInt(string a)
{
    ll x = 0LL;
    int cnt = 0;
    FORD(i, a.length() - 1, 0)
    {
        if (a[i] == '1' && cnt % 2 == 0) x += Pow2[cnt];
            else if (a[i] =='1' && cnt % 2 != 0) x -= Pow2[cnt];
        cnt++;
    }
    return x;
}

string xuli(string s)
{
    string res = "";

    for(int i = 1; i <= s.length() + 2; i++) res += '1';

    ll X = ToInt(s); ll Sum = ToInt(res); ll Y = Sum - X;

    string YY = ToAmHai(Y);

    ll ress = - infll; string Ress;

    if (YY.length() <= s.length()) return YY;

    FORV(i, 0, res.length())
    {
        string tmp = res;
        tmp[i] = '0';
        Sum = ToInt(tmp);
        Y = Sum - X;
        YY = ToAmHai(Y);
        if (YY.length() <= s.length())
        {
            if (Y > ress)
            {
                ress = Y;
                Ress = YY;
            }
        }
    }
    if (ress != - infll) return Ress;

    FORV(i, 0, res.length() - 1)
    {
        FORV(j, i + 1, res.length())
        {
            string tmp = res;
            tmp[i] = tmp[j] = '0';
            Sum = ToInt(tmp);
            Y = Sum - X;
            YY = ToAmHai(Y);
            if (YY.length() <= s.length())
            {
                if (Y > ress)
                {
                    ress = Y;
                    Ress = YY;
                }
            }
        }
    }
    return Ress;
}

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("maxnum.inp","r",stdin);
    freopen("maxnum.out","w",stdout);

    Pow2[0] = 1;
    FOR(i, 1, 63) Pow2[i] = Pow2[i-1] * 2;

    string s;

    while (cin >> s)
    {
        cout << xuli(s) << '\n';
    }
    return 0;
}
