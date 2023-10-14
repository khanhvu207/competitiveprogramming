#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
 
int flag_ = 0;
const int pp[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
const int tmp[11] = {0, 0, 0, 980, 949, 907, 854, 790, 715, 629, 532};
 
int len (int a)
{
    return a > 0 ? (int) log10((double) a) + 1 : 1;
}
 
int sorting (int a)
{
    vector<int> d;
    while (a > 0)
        d.push_back(a % 10), a /= 10;
    sort(d.begin(), d.end());
    int t = 0, p = 1;
    for (int i = 0; i < (int)d.size(); i++)
        t += d[i] * p, p *= 10;
    return t;
}
 
bool chk (int a)
{
    int zero = 0, t = len(a);
    while (a > 0)
        zero += (a % 10 == 0), flag_ = (a % 10 == 2), a /= 10;
    if (zero == t - 1) return true;
        else return false;
}
 
int rec (int a)
{
    int cnt = 0;
    vector<int> d;
    for (; a > 0;)
        d.push_back(a % 10), a /= 10;
    reverse(d.begin(), d.end());
    int flag = 1, one = 1;
    for (int i = 0; i < (int)d.size(); i++)
    {
        if (i == 0 && d[i] == 1) --one;
        if ((i == 0 && d[i] == 1) || d[i] < 1) continue;
        if (d[i] == 1 && one)
        {
            --one;
            continue;
        }
        if (i == (int)d.size() - 1)
        {
            if (flag) cnt += (10 + d[i]);
                else cnt += d[i] + 1;
            continue;
        }
        if (!flag)
            cnt += d[i] + 2;
        else
        {
            cnt += 11 + d[i];
            flag = 0;
        }
        //cout << i << ' ' << cnt << '\n';
    }
    //cout << cnt << '\n';
    return cnt - one;
}
 
int t, n;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("mgame.inp", "r", stdin);
    freopen("mgame.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n < 100)
        {
            if (n < 21) cout << 1000 - n;
                else cout << 1000 - (n % 10) - (n / 10) - 11;
            cout << '\n';
            continue;
        }
        if (n == 2000000000)
        {
            cout << 424 << '\n';
            continue;
        }
        int L = len(n);
        int cost = 1000 - tmp[L];
        if (pp[L] - 9 == n)
        {
            cout << tmp[L + 1] << '\n';
            continue;
        }
        if (n == (pp[len(n) - 1]))
        {
            cout << 1000 - cost - 10 << '\n';
            continue;
        }
        cost += (chk(n) ? (rec(n - 9) + 10) : rec(n));
        cout << 1000 - cost + (chk(n) && flag_) << '\n';
    }
    return 0;
}