#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m, a, b, d[1005];
vector<pair<pair<ll, ll>, ll> > EList;

int main()
{
    freopen("SDC.INP", "r", stdin);
    freopen("SDC.OUT", "w", stdout);

    cin >> n >> m >> a >> b;
    for (ll i = 0, u, v, cost; i < m; i++)
    {
        cin >> u >> v >> cost;
        EList.push_back({{u, v}, cost});
    }

    for (int i = 1; i <= n; i++) d[i] = a;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = EList[j].first.first;
            int v = EList[j].first.second;
            int c = EList[j].second;
            if (d[v] - d[u] > c) d[u] = d[v] - c;
            if (d[u] > b)
            {
                cout << "NO";
                return 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u = EList[i].first.first;
        int v = EList[i].first.second;
        int c = EList[i].second;
        if (d[v] - d[u] > c)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}
