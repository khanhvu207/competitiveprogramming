#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
const int N = 400;
int m, n, p[N], q[N];
vector <ii> res;
char convert[3] = {'W', 'D', 'L'};

void playD(int x)
{
    res.push_back({x, 1});
    res.push_back({x, 1});
    res.push_back({x, 1});
    res.push_back({x, 0});
    res.push_back({x, 0});
    res.push_back({x, 2});
}

void playT(int y)
{
    res.push_back({y, 1});
    res.push_back({y, 1});
    res.push_back({y, 0});
    res.push_back({y, 2});
}

int main()
{
    freopen("VECTOR.INP", "r", stdin);
    freopen("VECTOR.OUT", "w", stdout);

    scanf("%d", &m); for (int i = 0; i < m; i++) scanf("%d", &p[i]);
    scanf("%d", &n); for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    for (int i = 0; i < m; i++) playT(p[i]);
    for (int i = 0; i < n; i++) playD(q[i]);

    cout << res.size() << '\n';
    for (ii k : res) cout << k.first << ' ' << convert[k.second] << '\n';

    return 0;
}
