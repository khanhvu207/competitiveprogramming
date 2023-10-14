#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const long long linf = 1e16 + 10;

int n, a[2][N][2];

long long psum[2][N];
int ansc[2][N];

int ansp[2];

bool minimize(long long &x, long long y) {
    if (x > y) x = y; else return 0;
    return 1;
}
void solve() {
    long long ans = 0;
    for(int type = 0; type <= 1; type++) {
        vector<int> coor;
        for(int i = 1; i <= n; i++) {
            if (a[type][i][0] > a[type][i][1])
                swap(a[type][i][0], a[type][i][1]);
            for(int j = 0; j <= 1; j++) {
                coor.push_back(a[type][i][j]);
            }
        }
        sort(coor.begin(), coor.end());
        int nc = coor.size();

        memset(psum, 0, sizeof(psum));
        for(int i = 1; i <= n; i++) {
            int L = lower_bound(coor.begin(), coor.end(), a[type][i][0]) - coor.begin() + 1;
            int R = lower_bound(coor.begin(), coor.end(), a[type][i][1]) - coor.begin() + 1;

            psum[0][0]--; psum[0][L]++;
            psum[1][0] += a[type][i][0], psum[1][L] -= a[type][i][0];

            psum[0][R]++; psum[0][nc + 1]--;
            psum[1][R] -= a[type][i][1], psum[1][nc + 1] += a[type][i][1]; 
        }

        for(int j = 0; j <= 1; j++)
            for(int i = 1; i <= nc; i++) psum[j][i] += psum[j][i - 1];
        long long cans = linf;
        for(int i = 1; i <= nc; i++) 
            if (minimize(cans, psum[0][i] * coor[i - 1] + psum[1][i]))
                ansp[type] = coor[i - 1];
        ans += cans;
        for(int i = 1; i <= n; i++) {
            if (a[type][i][0] <= ansp[type] && ansp[type] <= a[type][i][1]) {
                ansc[type][i] = ansp[type];
                continue;
            }
            ansc[type][i] = (ansp[type] < a[type][i][0]) ? a[type][i][0] : a[type][i][1];
        }
    }
    cout << ans << '\n';
    cout << ansp[0] << " " << ansp[1] << '\n';
    for(int i = 1; i <= n; i++) {
        cout << ansc[0][i] << " " << ansc[1][i] << '\n';
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 1; j++) ans -= abs(ansp[j] - ansc[j][i]);
    assert(ans == 0);
}
int main() {
    freopen("tigersugar.inp", "r", stdin);
    freopen("tigersugar.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j <= 1; j++)
            for(int k = 0; k <= 1; k++) cin >> a[k][i][j];

    solve();
}
