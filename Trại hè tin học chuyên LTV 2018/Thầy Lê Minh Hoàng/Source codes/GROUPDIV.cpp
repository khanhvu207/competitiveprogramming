#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[300005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        for (int j = 0, u; j < x; j++) cin >> u, g[i].push_back(u);
    }


    return 0;
}
