/*
    World of Train (de moi)

    dp[i][j] = so day do dai i, da co j doan thoa man

    dp[i][j] -> dp[i'][j'] bang cach push_back (i' - i) chu cai nao do != c[i] vao duoi
    (luu y truong hop nhet lan dau)

    Ve co ban,
    dp[i][j] = dp[i-1][j] + dp[i-2][j] + ... + dp[i-d+1][k]
             + dp[i-d][j-1] + dp[i-d-1][j-2] + ...
    (chi co 2 ki tu trong bai nay)

    Gia su d = 3

    \j|0 1 2 3 4 5 6 7 8 9 101112131415
    i\|_______________________________________
    0 |         -
    1 |           x
    2 |             x
    3 |              x // (length - 1)
    4 |              x
    5 |              o
    6 |
    7 |
    -> tong don 2 lan
    f[i][j] = tong don doc
    g[i][j] = tong don cheo

    length = 1 ?
        null
    length > 1
        Bai toan <-> Dem so day +-+-+-... do dai length-1
                 <-> Bai WOT goc voi 2 ki tu

    BASE CASE:
    for(int i=1;i<=n;i++){
        dp[i][max(0, i - length + 1)] = 2;
    }

*/

#include <stdio.h>
#include <algorithm>
#include <assert.h>
using namespace std;
const int mod = 998244353;
const int N = 6420 + 5;

// careful when use
void fix_mod(int &x) {
    if (x >= mod)
        x -= mod;
    if (x < 0)
        x += mod;
}

int dp[N][N], f[N][N], g[N][N];
int n, length, no_subarray;
int get_col(int l,int r, int j) {
    l = max(1, l);
    if (l > r)  return 0;
    return f[r][j] - f[l-1][j];
}
int get_diagonal(int i,int j) {
    if (i < 1 || j < 0) return 0;
    int a = max(i, j+1);
    return g[i][j] - (j-a >= 0 ? g[i-a][j-a] : 0);
}
int main() {
#ifdef THEMIS
  freopen("SINGER.INP", "r", stdin);
  freopen("SINGER.OUT", "w", stdout);
#endif // THEMIS

    scanf("%d %d %d", &n, &length, &no_subarray);
    assert(2 <= length && length <= n+1);
    length--;

    // base cases
    for(int i=1; i<=n; i++) {
        dp[i][max(0, i - length + 1)] = 2;
    }

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=i; j++) {

            int col = get_col(i-length+1, i-1, j);
            fix_mod(col);
            int diagonal = get_diagonal(i - length, j - 1);
            fix_mod(diagonal);

            dp[i][j] += col + diagonal;
            fix_mod(dp[i][j]);

            f[i][j] = f[i-1][j] + dp[i][j];
            fix_mod(f[i][j]);
            g[i][j] = g[i-1][j-1] + dp[i][j];
            fix_mod(g[i][j]);
        }
    }

    printf("%d", dp[n][no_subarray]);
}
