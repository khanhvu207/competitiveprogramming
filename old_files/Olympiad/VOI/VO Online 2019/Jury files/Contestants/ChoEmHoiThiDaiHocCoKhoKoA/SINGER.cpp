#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fi(a,b,c) for(int a=b;a<=c;a++)
#define fo(a,b,c) for(int a=b;a>=c;a--)
#define long long long
#define pii pair<int,int>
#define mp make_pair

const int N = 7e3+1;

long n, d, t, ans;
int a[N];

bool Check(){
    deque<pii> qu_max, qu_min;
    qu_max.push_back(mp(0,0));
    qu_min.push_back(mp(0,0));
    fi(i,1,d-2){
        while (!qu_max.empty() && qu_max.back().first <= a[i])
            qu_max.pop_back();
        qu_max.push_back(mp(a[i],i));

        while (!qu_min.empty() && qu_min.back().first >= a[i])
            qu_min.pop_back();
        qu_min.push_back(mp(a[i],i));
    }

    int counts = 0;
    fi(i,d-1,n){
        //pop
        while (!qu_max.empty() && qu_max.front().second < i-d+1)
            qu_max.pop_front();
        while (!qu_min.empty() && qu_min.front().second < i-d+1)
            qu_min.pop_front();

        //push
        while (!qu_max.empty() && qu_max.back().first <= a[i])
            qu_max.pop_back();
        qu_max.push_back(mp(a[i],i));
        while (!qu_min.empty() && qu_min.back().first >= a[i])
            qu_min.pop_back();
        qu_min.push_back(mp(a[i],i));

        int mx = qu_max.front().first;
        int mn = qu_min.front().first;

        if (mx-mn <= 1)
            counts++;
    }

    return (counts==t);
}

void Try(int p){
    fi(i,-1,1){
        if (i == 0) continue;
        a[p] = a[p-1]+i;

        if (p == n)
            ans += Check();
        else
            Try(p+1);
    }
}

void Solve(){
    puts("0");
    exit(0);
}

main(){
    freopen("SINGER.inp","r",stdin);
    freopen("SINGER.out","w",stdout);

    scanf("%lld%lld%lld", &n, &d, &t);
    if (n <= 20)
        Try(1);
    else
        Solve();
    printf("%lld", ans);
}
