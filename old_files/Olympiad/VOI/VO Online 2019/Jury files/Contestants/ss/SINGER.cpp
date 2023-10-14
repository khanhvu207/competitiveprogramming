//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <cmath>
#include <climits>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 6420 + 15;
const int base = 998244353;

int n, m, tmp, res, d, t;
int a[N];
int f[N][N];

void sub2()
{
    d--;
    f[0][0] = 1;
    for (int i = 1; i < d; i++)
        f[i][0] = (f[i - 1][0] * 2) % base;
    f[0][0] = 2;
    for (int i = d; i <= n; i++)
        for (int j = 0; j <= t; j++)
        {
            int ss = 0, an = 0;
            for (int x = i - d + 1; x < i; x++) ss = (ss + f[x][j]) % base;
            for (int x = 0; x <= i - d; x++)
            {
                int m = (i - x);
                m = m - d + 1;
                if (j - m < 0) continue;
                an = (an + f[x][j - m]) % base;
            }
            f[i][j] = (ss + an) % base;
        }
    cout << f[n][t];
}

int s[N][N], tn[N][N];

void sol()
{
    d--;
    f[0][0] = 1;
    for (int i = 1; i < d; i++)
        f[i][0] = (f[i - 1][0] * 2) % base;
    f[0][0] = 2; s[0][0] = 2; tn[0][0] = 2;
    for (int i = 1; i < d; i++)
    {
        s[i][0] = (s[i - 1][0] + f[i][0]) % base;
        tn[i][0] = f[i][0];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= t; j++)
        {
            tn[i][j] = tn[i - 1][j - 1];
        }
    //n = 8, t = 1;
    for (int i = d; i <= n; i++)
        for (int j = 0; j <= t; j++)
        {
            int ss = 0, an = 0;
            ss = ((s[i - 1][j] - s[i - d][j]) % base + base) % base;
            int m = min(j, i - d + 1);
            int k = i - d + 1;
            //for (int x = 1; x <= m; x++)
            //    an = (an + f[k - x][j - x]) % base;
            //cout << i <<" "<< j <<" "<< k <<" "<< j <<" "<< an <<" "<< tn[k - 1][j - 1] <<"\n";
            an = tn[k - 1][j - 1];

            f[i][j] = (ss + an) % base;
            s[i][j] = (s[i - 1][j] + f[i][j]) % base;
            if (j == 0) tn[i][j] = f[i][0];
            else tn[i][j] = (tn[i - 1][j - 1] + f[i][j]) % base;

        }
    cout << f[n][t];
}

int main()
{
    #define file "SINGER"
    freopen(file".inp" , "r" , stdin);
    freopen(file".out" , "w" , stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    cin >> n >> d >> t;
    res = 1;
    for (int i = 1; i <= n; i++) res = (res + res) % base;
    if (n <= 420) return sub2(), 0;
    sol();

    return 0;
}
