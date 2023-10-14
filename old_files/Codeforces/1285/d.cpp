// Oddly trivial

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;

int Go(vector<int>& v, int cur) {
    if (v.empty() || cur < 0) return 0;
    vector<int> on, off;
    for (int x : v) {
        if (((x >> cur) & 1) == 1) on.push_back(x);
            else off.push_back(x);
    }
    if (on.empty()) return Go(off, cur - 1);
    if (off.empty()) return Go(on, cur - 1);
    return (1 << cur) + min(Go(on, cur - 1), Go(off, cur - 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    cout << Go(a, 30);
}