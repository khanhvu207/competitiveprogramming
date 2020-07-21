#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int lastOne = 1e9, lastZero = 1e9;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x) lastOne = i + 1;
        else lastZero = i + 1;
    }
    cout << min(lastOne, lastZero);
}