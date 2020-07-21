#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll shift[65];

ll modulo(ll K, ll m) {
    if (K > 0) return K % m;
    ll k = -K / m;
    return (K + (k + 1LL) * m) % m;
}

ll getLevel(ll X) {
    ll cnt = 0;
    while (X > 0)
        X >>= 1LL, ++cnt;
    return cnt;
}

ll initPos(ll X) {
    ll lv = getLevel(X);
    return X - (1LL << (lv - 1LL));
}

void printRes(ll X) {
    ll Y;
    ll lv = getLevel(X);
    ll numNodes = (1LL << lv) - (1LL << (lv - 1LL));
    Y = (initPos(X) + modulo(shift[lv], numNodes)) % numNodes;
    Y += (1LL << (lv - 1LL));
    cout << X << ' ';
    Y >>= 1LL;
    while (Y > 0) {
        lv = getLevel(Y);
        numNodes = (1LL << lv) - (1LL << (lv - 1LL));
        ll pos = (initPos(Y) + modulo(-1LL * shift[lv], numNodes)) % numNodes;
        cout << (1LL << (lv - 1LL)) + pos << ' ';
        Y >>= 1LL;
    } 
    cout << '\n';
}

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        int t;
        ll X;
        cin >> t >> X;
        if (t == 3) {
            printRes(X);
            continue;
        }
        ll K; 
        cin >> K;
        int top = getLevel(X);
        int low = t == 1 ? top : 60;
        ll aux = 1LL;
        for (ll i = top; i <= low; ++i) {
            ll numNodes = (1LL << i) - (1LL << (i - 1LL));
            (shift[i] += aux % numNodes * modulo(K, numNodes) % numNodes) %= numNodes;
            aux <<= 1LL;
        } 
    }
}