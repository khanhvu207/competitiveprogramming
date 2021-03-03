#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int n, ans = 0;
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("muave.inp", "r", stdin);
    freopen("muave.out", "w", stdout);
    cin >> n;
    for (int i = 0, h; i < n; ++i)
    {
        cin >> h;
        ans += (int)s.size();
        while (!s.empty() && s.top() < h) s.pop();
        s.push(h);
    }
    cout << ans;
}
