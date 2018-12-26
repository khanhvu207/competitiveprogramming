#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int N = 100015;

int n, m;
bool p[N];
vector<int> prime;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("10139.inp", "r", stdin);
    freopen("10139.out", "w", stdout);

    for (int i = 2; i <= 100000; ++i)
        p[i] = true;
    for (int i = 2; i <= sqrt(100000); ++i)
        if (p[i])
            for (int j = 2; j <= 100000 / i; ++j)
                p[i * j] = false;
    for (int i = 2; i <= 100000; ++i)
        if (p[i]) prime.push_back(i);

    while (cin >> m >> n) {
        int x = n;
        bool good = true;
        for (int i = 0; i < (int)prime.size() && p[i] <= sqrt(n); ++i)
            if (n % prime[i] == 0) {
                int cnt = 0;
                while (n % prime[i] == 0)
                    n /= prime[i], ++cnt;
                int t = m;
                while (t > 0) {
                    cnt -= t / prime[i];
                    t /= prime[i];
                }
                if (cnt > 0)
                    good = false;
            }
        if (n > 1 && n > m) {
            good = false;
        }
        cout << x << ' ';
        if (!good)
            cout << "does not divide ";
        else
            cout << "divides ";
        cout << m << "!\n";
    }
}
