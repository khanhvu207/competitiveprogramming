#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("SINGER.INP","r",stdin)
#define OUT freopen("SINGER.OUT","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll K = 998244353;
const ll N = 6425;


ll d[N][N];
ll e[N][N];

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    d[0][0] = 1;
    int n, D, t;
    cin >> n >> D >> t;
    D--;

    if (D != 1) {
    	d[1][0] = 1; 
    }
    else {
    	d[1][1] = 1;
    }

    FOR (i, 2, n) {
    	if (i >= D + 3) {
    		d[i][0] = (2 * d[i - 1][0] - d[i - D][0]) % K;
    		d[i][0] = (d[i][0] + K) % K;

	    	FOR (j, 1, i) {
	    		d[i][j] = (d[i - 1][j - 1] + 2 * d[i - 1][j] - 2 * d[i - 2][j - 1]) % K;
	    		if (i >= D) {
	    			d[i][j] = (d[i][j] + d[i - D][j - 1] - d[i - D][j]) % K;
	    		}
	    		d[i][j] = (d[i][j] + K) % K;
	    		//cout << i << " " << j << " " << d[i][j] << endl;
	    	}
	    	//cout << endl;
	    }
	    else if (i < D) {
	    	FOR (j, 0, i) {
	    		d[i][j] = 2 * d[i - 1][j] % K;
	    	}
	    }
	    else {
	    	FOR (j, 0, i) {
		    	FOR (k, 0, i - 1) {
	    			if (j >= i - k - D + 1) d[i][j] = (d[i][j] + d[k][j - max(0, i - k - D + 1)]) % K;
	    		}
	    	}
	    }
    }
    /*
    e[0][0] = 1;
    FOR (i, 1, n) {
    	FOR (j, 0, i) {
    		FOR (k, 0, i - 1) {
    			if (j >= i - k - D + 1) e[i][j] = (e[i][j] + e[k][j - max(0, i - k - D + 1)]) % K;
    		}
    		cout << i << " " << j << " " << e[i][j] << " " << d[i][j] << endl;
    	}
    	cout << endl;
    }
    cout << e[n][t] * 2 << endl; 
    */
    cout << d[n][t] * 2 % K << endl;
    
    
    return 0;
}