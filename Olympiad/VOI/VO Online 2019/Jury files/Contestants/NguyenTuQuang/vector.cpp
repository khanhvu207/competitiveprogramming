#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;

int tr[N];
int h[2][N];
void prepare() {
    for(int i = 2; i < N; i++) if (!tr[i]) 
        for(int j = i; j < N; j += i) tr[j] = i; 
    for(int j = 0; j <= 1; j++) {
        int n;
        cin >> n;
        while (n--) {
            int val;
            cin >> val;
            while (val > 1) {
                h[j][tr[val]]++;
                val /= tr[val];
            }
        }
    }
}
const string res = "DWL";
void solve() {
    vector<int> v[3];
    for(int i = 2; i < N; i++) if (h[0][i] || h[1][i]) {
        int u1 = h[0][i], u2 = h[1][i];
        if (u1 % 2 == 1) {
            v[0].push_back(i);
            u1++;
        }
        int p2 = u2 + u1 / 2;
        if (p2 % 2) {
            v[0].push_back(i);
            v[0].push_back(i);
            u1 += 2;
        }
        while (u1) {
            v[1].push_back(i);
            u1 -=2, u2++;
        }
        while (u2) {
            v[2].push_back(i);
            u2 -= 2;
        }
    }
    cout << v[0].size() + v[1].size() + v[2].size() << '\n';
    for(int i = 0; i < 3; i++) 
        for(auto j : v[i]) cout << j << " " << res[i] << '\n';
}
int main() {
    freopen("vector.inp", "r", stdin);
    freopen("vector.out", "w", stdout);
    prepare();
    solve();
}
