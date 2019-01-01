#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    freopen("10139.inp", "r", stdin);
    freopen("10139.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    for (int n, m, x; cin >> n >> m;) {
        x = m;
        for (int i = 2; i * i <= x; ++i)
            if (m % i == 0) {
                int cnt = 0;
                while (x % i == 0) x /= i, ++cnt;
                for (int y = n; y && cnt > 0; cnt -= y /= i);
                if (cnt > 0) goto NO;
            }
        if (x > 1 && n < x) goto NO;
        cout << m << " divides " << n << "!\n"; continue;
        NO: cout << m << " does not divide " << n << "!\n";
    }
}
