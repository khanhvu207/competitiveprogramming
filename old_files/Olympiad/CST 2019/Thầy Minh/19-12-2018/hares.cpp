#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;


int n;
int total = 0;
int x[4005], y[4005], w[4005];
int ans = 0;
const double EPS = 1e-9;
int main () {
    freopen("hares.inp", "r", stdin);
    freopen("hares.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &w[i]);
        total += w[i];
    }
    for (int i = 0; i < n; ++i) {
        vector<pair<double, int> > a;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                a.pb(mp(atan2(y[j] - y[i], x[j] - x[i]), w[j]));
            }
        }
        sort(a.begin(), a.end());
        int cur = 0;
        int b = 0;
        int f = 0;
        for (f; f < a.size(); ++f) {
            for (b; (b < a.size() && a[b].x <= a[f].x + M_PI) || (b < 2 * a.size() && a[b % a.size()].x + M_PI * 2 <= a[f].x + M_PI); ++b) {
                cur += a[b % a.size()].y;
            }
            for (f; f < a.size() - 1 && abs(a[f + 1].x - a[f].x) < EPS; ++f) {
                cur -= a[f].y;
            }
            if (cur + w[i] > ans)
                ans = cur + w[i];
            if (cur >  ans)
                ans = cur;
            cur -= a[f].y;
        }
    }
    printf("%d\n", ans);
    return 0;
}