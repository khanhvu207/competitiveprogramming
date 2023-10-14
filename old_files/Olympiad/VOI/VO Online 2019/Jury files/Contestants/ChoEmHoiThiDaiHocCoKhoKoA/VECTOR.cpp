#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define fi(a,b,c) for(int a=b;a<=c;a++)
#define fo(a,b,c) for(int a=b;a>=c;a--)
#define long long long
#define pll pair<long,long>
#define mp make_pair

const int N = 1e5+1;

int n, m;
long a[N], b[N];
vector<pll> list_ans;

void AdivP(long p){
    list_ans.push_back(mp(p,'D'));
    list_ans.push_back(mp(p,'D'));
    list_ans.push_back(mp(p,'W'));
    list_ans.push_back(mp(p,'L'));
}

void BdivP(long p){
    list_ans.push_back(mp(p,'D'));
    list_ans.push_back(mp(p,'W'));
    AdivP(p);
}

main(){
    freopen("VECTOR.inp","r",stdin);
    freopen("VECTOR.out","w",stdout);

    scanf("%d", &n);
    fi(i,1,n)
        scanf("%lld", &a[i]);
    scanf("%d", &m);
    fi(i,1,m)
        scanf("%lld", &b[i]);

    fi(i,1,n)
        AdivP(a[i]);
    fi(i,1,m)
        BdivP(b[i]);

    printf("%d\n", list_ans.size());
    fi(i,0,(int)list_ans.size()-1)
        printf("%lld %c\n", list_ans[i].first, (char)list_ans[i].second);

    /*long c = 1, d = 1;
    fi(i,1,n)
        c *= a[i];
    fi(i,1,m)
        d *= b[i];
    fi(i,0,list_ans.size()-1){
        if (list_ans[i].second == 'W'){
            c *= list_ans[i].first;
            d /= list_ans[i].first*list_ans[i].first;
        }
        if (list_ans[i].second == 'L'){
            c /= list_ans[i].first*list_ans[i].first;
        }
        if (list_ans[i].second == 'D'){
            d *= list_ans[i].first;
        }
    }
    cout << c << " " << d << endl;*/
}
