/*
    Wedding
    Subtask 2: k <= 10^5, mod = 2

    Brute m, n, which have the following property:
    m * n = k
    2 <= n, m < k
    Check whether the array can be a concatenation of m string A (length n)
    and string 0 (length n)

    -> S = f(P), T = A

    O (divisors(k) * k)
*/
#include <bits/stdc++.h>
using namespace std;

int k, mod;
int s[100005];
int t[100005];
int p[100005];
int main(){
#ifdef THEMIS
    freopen("WEDDING.INP", "r", stdin);
    freopen("WEDDING.OUT", "w", stdout);
#endif // THEMIS

    iostream::sync_with_stdio(0);
    cin >> k >> mod;
    for(int i=0;i<k;i++)
        cin >> p[i];

    for(int n=2;n<k;n++){
        if (k % n)  continue;
        int m = k / n;

        bool ok = 1;
        vector <int> pos;

        for(int i = 0; i < m; i++){
            bool onBit = 0;
            for(int j=0;j< n;j++){
                onBit |= p[i*n + j];
            }
            if (!onBit) continue;

            pos.push_back(i);
            if (pos.size() == 1)    continue;

            for(int j=0;j< n;j++){
                onBit &= (p[i*n + j] == p[pos[0] * n + j]);
            }
            if (!onBit) ok = 0;
        }
        if (ok){
             cout << "YES\n";
             if (pos.empty()){
                cout << m << ' '; while (m--)   cout << 0 << ' '; cout << endl;
                cout << n << ' '; while (n--)   cout << 0 << ' '; //cout << endl;
             }
             else{
                for(int i=0;i<n;i++)    t[i] = p[pos[0] * n + i];
                for(auto v: pos)    s[v] = 1;
                cout << m << ' '; for(int ii=0;ii<m;ii++) cout << s[ii] << ' '; cout << '\n';
                cout << n << ' '; for(int ii=0;ii<n;ii++) cout << t[ii] << ' '; //cout << '\n';
             }
             return 0;
        }
    }
    cout << "NO";
}
