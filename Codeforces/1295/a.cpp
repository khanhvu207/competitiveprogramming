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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int numOne = n / 2;
        int numSev = 0;
        if (n & 1 && numOne > 0) 
            --numOne, ++numSev;
        while (numSev) {
            cout << 7;
            --numSev; 
        }
        while (numOne) {
            cout << 1;
            --numOne;
        } 
        cout << '\n';
    }
}