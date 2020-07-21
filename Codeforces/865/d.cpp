#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    Q.push(1e18);
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (Q.top() < x) {            
            ans += x - Q.top();
            Q.pop();
            Q.push(x);
        }
        Q.push(x);
    }
    cout << ans;
}