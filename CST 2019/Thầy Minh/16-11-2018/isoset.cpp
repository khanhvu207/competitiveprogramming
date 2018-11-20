#include <iostream>
#include <cstdio>
using namespace std;

char t;
string a, b;
long long C[10][10], fact[10];

long long queryv (string P, string T)
{
    if ((int)P.size()!=(int)T.size()) return false;
    int lua[10];
    for (int i=0; i<=9; ++i)
        lua[i]=-1;
    for (int i=0; i<(int)P.size(); ++i)
    {
        int x=P[i]-'0';
        int y=T[i]-'0';
        if (lua[x]!=-1&&lua[x]!=y) return false;
        else if (lua[x]==-1) lua[x]=y;
    }
    return true;
}

long long querys (string P)
{
    bool lua[10];
    int cnt=0;
    for (int i=0; i<=9; ++i)
        lua[i]=0;
    for (int i=0; i<(int)P.size(); ++i)
    {
        int x=P[i]-'0';
        if (!lua[x]) ++cnt;
        lua[x]=1;
    }
    long long res=9*C[9][cnt-1]*fact[cnt-1];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("isoset.inp", "r", stdin);
    freopen("isoset.out", "w", stdout);
    for (int i=0; i<=9; ++i)
        C[i][0]=1ll;
    for (int i=1; i<=9; ++i)
        for (int j=1; j<=i; ++j)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    fact[0]=1ll;
    for (int i=1; i<=9; ++i)
        fact[i]=fact[i-1]*i*1ll;

    while (cin >> t)
    {
        if (t=='V')
        {
            cin >> a >> b;
            cout << (queryv(a, b)?"YES\n":"NO\n");
        } else
        {
            cin >> a;
            cout << querys(a) << '\n';
        }
    }
    return 0;
}
