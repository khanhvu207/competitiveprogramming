#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int d, w[1015], f, t, s[1015], cnt[1015];
vector <int> a[1015], barking[2015];

int main() {
    freopen("dogs.inp", "r", stdin);
    freopen("dogs.out", "w", stdout);
    cin >> d;
    for (int i = 1; i <= d; ++i)
        cin >> w[i];
    cin >> f;
    for (int u, v; f--;)
        cin >> u >> v,
        a[u].push_back(v);
    cin >> t;
    s[1] = 1; barking[0].push_back(1);
    for (int i = 0; i <= t; ++i)
        for (int u: barking[i]) {
            ++cnt[u];
            for (int v: a[u])
                if (s[v] <= i)
                    barking[i + w[v]].push_back(v),
                    s[v] = i + w[v] + 1;
        }
    for (int i = 1; i <= d; ++i)
        cout << cnt[i] << '\n';
}
