/*
    Wedding
    Subtask 1: k <= 12, mod <= 7

    Brute n, m, which have the following property:
    n * m = k
    2 <= n, m < k
    7 ^ 6 = 117649 = 1e5
    O (divisors(k) * Mod^(max(n+k/n)))
*/
#include <bits/stdc++.h>
using namespace std;

int k, mod;
int s[10];
int t[10];
int p[20];
int main(){
#ifdef THEMIS
    freopen("WEDDING.INP", "r", stdin);
    freopen("WEDDING.OUT", "w", stdout);
#endif // THEMIS

    cin >> k >> mod;
    for(int i=0;i<k;i++)
        cin >> p[i];

    for(int n=2;n<k;n++){
        if (k % n)  continue;
        int m = k / n;


        int boundm = 1;
        for(int i=1;i<=m;i++)   boundm *= mod;
        int boundn = 1;
        for(int i=1;i<=n;i++)   boundn *= mod;

        for(int i=0;i<boundm;i++){
            for(int j=0;j<boundn;j++){

                int x = i;
                int y = j;

                for(int _=0;_<m;_++){
                    s[_] = x % mod;
                    x /= mod;
                }
                for(int _=0;_<n;_++){
                    t[_] = y % mod;
                    y /= mod;
                }

                bool ok = 1;
                // check
                for(int ii=0;ii<m;ii++){
                    for(int jj=0;jj<n;jj++){
                        if (s[ii] * t[jj] % mod != p[ii * n + jj]) ok = 0;
                    }
                }
                if (ok){
                    cout << "YES\n";
                    cout << m << ' '; for(int ii=0;ii<m;ii++) cout << s[ii] << ' '; cout << '\n';
                    cout << n << ' '; for(int ii=0;ii<n;ii++) cout << t[ii] << ' '; //cout << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}
