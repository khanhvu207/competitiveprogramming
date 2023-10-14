#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int prevv, c, d;
    cout << "? 0 0" << '\n' << flush;
    cin >> prevv;
    c = d = 0;
    for (int i = 29; i >= 0; --i) {
        int a, b;
        cout << "? " << c + (1 << i) << ' ' << d + (1 << i) << '\n' << flush;
        cin >> a;
        cout << "? " << c << ' ' << d + (1 << i) << '\n' << flush;
        cin >> b;
        if (prevv == -1) {
            if (a == prevv) {
                if (b != prevv) c += (1 << i), d += (1 << i);
            } 
            else {
                d += (1 << i);
                prevv = b;
            }
        } 
        else if (prevv == 0) {
            if (b == 1) c += (1 << i), d += (1 << i);
        }
        else if (prevv == 1) {
            if (a == prevv) {
                if (b == prevv) c += (1 << i), d += (1 << i);
            }
            else {
                c += (1 << i);
                prevv = b;
            }
        }
    }
    cout << "! " << c << ' ' << d << '\n' << flush;
}