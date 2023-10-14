#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int time(int r, int m, const char *bridge) {
    int i = 0, res = 1;
    while (i + r <= m) {
        res++;
        i += r;
        while (bridge[i] == '1') i--;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    freopen("cross.inp", "r", stdin);
    freopen("cross.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) 
        cin >> x;
    string bridge; cin >> bridge;
    bridge = '0' + bridge + '0';
    vector<int> cache(101, 0);
    for (int &x: a) {
        if (!cache[x]) 
            x = cache[x] = time(x, m, bridge.data());
        else x = cache[x];
    }
    sort(a.begin(), a.end());
    if (n == 1) cout << a[0];
    else if (n == 2) cout << a[1];
    else {
        int f0 = a[0], f1 = a[1];
        for (int i=2; i<n; i++) {
            int f2 = min(f0 + a[0] + 2*a[1] + a[i], f1 + a[0] + a[i]);
            f0 = f1, f1 = f2;
        }
        cout << f1;
    }
    return 0;
}