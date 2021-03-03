#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, a, b;
long long total=0;
vector<pair<long long, long long> > res;
priority_queue<pair<long long, int> > q;
pair<pair<long long, long long>, int> t[100015];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("diamond.inp", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> a >> b;
    for (int i=1; i<=n; ++i)
        cin >> t[i].first.first >> t[i].first.second,
        t[i].second=i;
    sort(t+1, t+n+1);
    int tm=a, tr=1;
    while (tm<=b)
    {
        for (; t[tr].first.first<=tm; ++tr)
            q.push({t[tr].first.second, t[tr].second});
        if (q.empty())
        {
            if (tr<=n&&t[tr].first.first<=b)
            {
                tm=t[tr].first.first;
            } else break;
        } else
        {
            total+=q.top().first;
            res.push_back({tm, q.top().second});
            q.pop();
            ++tm;
        }
    }
    cout << total << '\n';
    for (int i=0; i<(int)res.size(); ++i)
        cout << res[i].first << ' ' << res[i].second << '\n';
}
