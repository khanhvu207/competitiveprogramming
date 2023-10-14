#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("vector.inp", "r", stdin);
    freopen("vector.out", "w", stdout);
    int n, x;
    vector <pair <int, char> > ans;
    cin >> n;
    while (n--) {
        cin >> x;
        ans.push_back(make_pair(x, 'D'));
        ans.push_back(make_pair(x, 'D'));
        ans.push_back(make_pair(x, 'W'));
        ans.push_back(make_pair(x, 'L'));
    }
    cin >> n;
    while (n--) {
        cin >> x;
        ans.push_back(make_pair(x, 'D'));
        ans.push_back(make_pair(x, 'D'));
        ans.push_back(make_pair(x, 'D'));
        ans.push_back(make_pair(x, 'W'));
        ans.push_back(make_pair(x, 'W'));
        ans.push_back(make_pair(x, 'L'));
    }
    cout << ans.size() << '\n';
    for (auto x: ans) cout << x.first << ' ' << x.second << '\n';
    return 0;
}
