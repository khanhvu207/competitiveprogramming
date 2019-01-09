// ILTH
#include <bits/stdc++.h>
#define FORU(i,a,b) for(int i = (a); i<=(b); i++)
#define FORD(i,a,b) for(int i = (a); i>=(b); i--)
#define MOD 998244353
using namespace std;
int x[200], N, D, T, res;
int Tenter(){
    cin >> N >> D >> T;
    return 0;
}
bool check(){
    int ans = 0;
    FORU(i,0,N-D+1){
        int mmin = INT_MAX, mmax = INT_MIN;
        FORU(j,i,i+D-1){
            mmin = min(mmin,x[j]);
            mmax = max(mmax,x[j]);
        }
        if (mmax - mmin <= 1) ans++;
    }
    if (ans == T) res++;
    return 0;
}
int gen(int i){
    if (i>N) check();
    else{
        FORU(k,-2,2)
            if (abs(k - x[i-1]) == 1){
                x[i] = k;
                gen(i+1);
            }
    }
    return 0;
}

int Tsolve(){
    gen(1);
    cout << res % (MOD);
    return 0;
}
int main(){
    freopen("SINGER.INP","r",stdin);
    freopen("SINGER.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Tenter();
    Tsolve();
    return 0;
}
