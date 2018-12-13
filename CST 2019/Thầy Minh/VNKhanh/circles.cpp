#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

#define ii pair<int,int>

using namespace std;
const int maxn = 300010;
int n;
ii cir[maxn];
stack<int> st,sum;

int main()
{
    freopen("CIRCLES.INP","r",stdin);
    freopen("CIRCLES.OUT","w",stdout);

    scanf("%d\n",&n);
    int x,r;
    for (int i=1; i<=n; ++i){
        scanf("%d %d\n",&x,&r);
        cir[i] = ii(x-r,-x-r);
    }
    sort(cir+1,cir+n+1);

    int ans = 0;

    st.push(0);
    sum.push(0);

//    for (int i=1; i<=n; ++i){
//        cerr << cir[i].first << " " << cir[i].second << endl;
//    }
    cir[n+1] = ii(2*1e9 + 1,0);
    for (int i=1; i<=n+1; ++i){
        while (st.size()>1 && cir[i].first>=-cir[st.top()].second){
            r = -(cir[st.top()].first + cir[st.top()].second)/2;
            st.pop();

            if (sum.top()==r) ans+=2; else ans++;
            sum.pop();
            sum.top() += r;
        }

        st.push(i);
        sum.push(0);
    }

    printf("%d\n",ans+1);
    return 0;
}
