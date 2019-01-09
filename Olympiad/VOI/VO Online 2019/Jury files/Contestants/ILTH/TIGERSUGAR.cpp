// ILTH
#include <bits/stdc++.h>
#define FORU(i,a,b) for(long long i = (a); i<=(b); i++)
#define FORD(i,a,b) for(long long i = (a); i>=(b); i--)
#define mp make_pair
using namespace std;
const int PMTH = 100005;
struct data{
    int x1, y1, x2, y2;
}e[PMTH];
int N;
int Tenter(){
    cin >> N;
    FORU(i,1,N) cin >> e[i].x1 >> e[i].y1 >> e[i].x2 >> e[i].y2;
    return 0;
}
int calc(int x, int y, int u, int v){
    return abs(x-u) + abs(y-v);
}

int Tsolve(){
    int res = 0;
    FORU(i,2,N) res += calc(e[1].x1,e[1].y1,e[i].x1,e[i].y1);
    cout << res << "\n";
    FORU(i,1,N) cout << e[i].x1 << " " << e[i].y1 << "\n";
    return 0;
}

int main(){
    freopen("TIGERSUGAR.INP","r",stdin);
    freopen("TIGERSUGAR.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Tenter();
    Tsolve();
    return 0;
}
