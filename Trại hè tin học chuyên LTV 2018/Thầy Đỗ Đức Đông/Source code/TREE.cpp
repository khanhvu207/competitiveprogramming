#include <bits/stdc++.h>

using namespace std;

int n, d[100005];
set<pair<int, int> > S;

int main()
{
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];

    for (int i = 1; i <= n; i++) S.insert(pair<int, int> (d[i], i));
    while (!S.empty())
    {
        pair<int, int> low = *S.begin();
        pair<int, int> high = *S.rbegin();
        S.erase(low);
        S.erase(high);
        cout << low.second << ' ' << high.second << '\n';
        if (low.first > 1) S.insert(pair<int, int> (low.first - 1, low.second));
        if (high.first > 1) S.insert(pair<int, int> (high.first - 1, high.second));
    }
    return 0;
}
