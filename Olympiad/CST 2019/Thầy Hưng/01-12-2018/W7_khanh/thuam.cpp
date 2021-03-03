#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

int n, m, c, a[1000015];
deque<int> dqmin, dqmax;
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("thuam.inp", "r", stdin);
    freopen("thuam.out", "w", stdout);

    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i >= m) while (!dqmin.empty() && dqmin.front() <= i - m) dqmin.pop_front();
        if (i >= m) while (!dqmax.empty() && dqmax.front() <= i - m) dqmax.pop_front();
        while (!dqmin.empty() && a[dqmin.back()] > a[i]) dqmin.pop_back();
        while (!dqmax.empty() && a[dqmax.back()] < a[i]) dqmax.pop_back();
        dqmin.push_back(i);
        dqmax.push_back(i);
        if (i < m - 1) continue;
        if (a[dqmax.front()] - a[dqmin.front()] <= c) res.push_back(i - m + 2);
    }
    if (res.empty())
        cout << 0;
    else
        for (int i = 0; i < (int)res.size(); ++i)
            cout << res[i] << '\n';
}
