#include <iostream>
#include <cstdio>
using namespace std;
const int N = 50015;

int n, a[N], pref[N], suff[N], auxL[N], auxR[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("sseq.inp", "r", stdin);
    freopen("sseq.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    pref[0] = auxL[0] = 0;
    for (int i = 1; i < n; ++i) {
        auxL[i] = max(0, a[i - 1] + auxL[i - 1] - a[i]);
        pref[i] = pref[i - 1] + auxL[i];
    }
    suff[n - 1] = auxR[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        auxR[i] = max(0, a[i + 1] + auxR[i + 1] - a[i]);
        suff[i] = suff[i + 1] + auxR[i];
    }
    int res = 2e9, p = 0;
    for (int i = 0; i < n + 1; ++i)
        if (i == 0 && suff[i] < res) {
            res = suff[i];
            p = i;
        } else if (i == n && pref[n - 1] < res) {
            res = pref[i];
            p = i;
        } else if (pref[i - 1] + suff[i] < res) {
            res = pref[i - 1] + suff[i];
            p = i;
        }
    cout << res << '\n';
    for (int i = 0; i < p; ++i)
        cout << auxL[i] << ' ';
    for (int i = p; i < n; ++i)
        cout << auxR[i] << ' ';
}
