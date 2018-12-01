#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int n, a[2000015], p[2000015];
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("khongam.inp", "r", stdin);
    freopen("khongam.out", "w", stdout);

    while (cin >> n)
    {
        if (n < 1) return 0;
        for (int i = 0; i < n; ++i)
            cin >> a[i], a[i + n] = a[i];
        for (int i = 0; i < 2 * n; ++i)
            p[i] = (i < 1 ? 0 : p[i - 1]) + a[i];
        dq.clear();
        for (int i = 0; i < n; ++i)
        {
            while (!dq.empty() && p[i] <= p[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        int cnt = p[dq.front()] >= 0;
        for (int l = 1, r = n; r < 2 * n - 1; ++l, ++r)
        {
            while (!dq.empty() && dq.front() < l) dq.pop_front();
            while (!dq.empty() && p[r] <= p[dq.back()]) dq.pop_back();
            dq.push_back(r);
            if (p[dq.front()] - p[l - 1] >= 0) ++cnt;
        }
        cout << cnt << '\n';
    }
}
