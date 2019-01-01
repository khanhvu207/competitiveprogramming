#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

stack <int> s;
long long res;

int main() {
    freopen("xoaso.inp", "r", stdin);
    freopen("xoaso.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int x; n--;) {
        cin >> x;
        while (s.size() > 1 && s.top() < x) {
            s.pop();
            if (s.top() < x) res += s.top();
            else {res += x; break;}
        }
        if (s.size() == 1 && s.top() < x)
            s.pop(), res += x;
        s.push(x);
    }
    while (s.size() > 1)
        s.pop(), res += s.top();
    cout << res;
}
