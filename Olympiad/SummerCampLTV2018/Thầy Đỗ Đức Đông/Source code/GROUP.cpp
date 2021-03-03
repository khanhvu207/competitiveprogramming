#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> pri;
queue<pair<int, int> > q;
vector<pair<int, int> > res;
bool p[2000005];

void sieve(int x)
{
    memset(p, true, sizeof p);
    p[1] = false;
    for (int i = 2; i <= sqrt(x); i++) if (p[i])
    {
        p[i] = true;
        for (int j = 2; j <= (x / i); j++) p[i * j] = false;
    }
    for (int i = 2; i <= x; i++) if (p[i]) pri.push_back(i);
}

int main()
{
    freopen("GROUP.INP", "r", stdin);
    freopen("GROUP.OUT", "w", stdout);
    cin >> n;
    sieve(n * 2 + 1);

    int I = n, cnt = 0;
    while (I > 0)
    {
        int pos = upper_bound(pri.begin(), pri.end(), I) - pri.begin();
        int R = I, L = pri[pos] - I; I = L - 1;
        cnt += (R - L + 1) / 2;
        q.push({L, R});
    }
    cout << cnt << '\n';
    while (q.size())
    {
        int L = q.front().first, R = q.front().second;
        q.pop();
        while (L <= R) cout << L << ' ' << R << '\n';
    }
    return 0;
}
