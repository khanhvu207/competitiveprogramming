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
const int N = 100015;

int n, m, tmp, res;
struct data
{
    int gt;
    char c;
};
data ans[N];
int a[N], b[N];

void add(int gt, char c)
{
    res++;
    ans[res].gt = gt, ans[res].c = c;
}

int main()
{
    #define file "VECTOR"
    freopen(file".inp" , "r" , stdin);
    freopen(file".out" , "w" , stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++)
        b[i + m] = a[i];
    m = m + n;
    for (int i = 1; i <= n; i++) add(a[i], 'D');
    for (int i = 1; i <= n; i++) add(a[i], 'W');
    for (int i = 1; i <= m; i++)
    {
        add(b[i], 'D'), add(b[i], 'D'), add(b[i], 'W'), add(b[i], 'L');
    }
    cout << res <<"\n";
    for (int i = 1; i <= res; i++) cout << ans[i].gt <<" "<< ans[i].c <<"\n";

    return 0;
}
