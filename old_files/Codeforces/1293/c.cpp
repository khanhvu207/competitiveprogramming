#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<bool>> blocked(3, vector<bool>(n + 5, false));
    int cntBlocked = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int rowToCheck;
        if (x == 1) rowToCheck = 2;
        else rowToCheck = 1;
        int check = 0;
        if (y > 1) check += blocked[rowToCheck][y - 1];
        if (y + 1 <= n) check += blocked[rowToCheck][y + 1];
        check += blocked[rowToCheck][y];
        if (check > 0) {
            if (!blocked[x][y]) cntBlocked += check;
            else cntBlocked -= check;
        }
        blocked[x][y] = !blocked[x][y];
        cout << (cntBlocked > 0 ? "NO\n" : "YES\n");
    }
}