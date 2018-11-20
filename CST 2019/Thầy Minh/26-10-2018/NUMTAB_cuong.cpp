#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

#define ii pair<int,int>

using namespace std;
const int maxn = 1001;

int n,m,a[maxn][maxn],th[maxn][maxn],tw[maxn][maxn];
int st[maxn],top,f[maxn][maxn];
ii h[maxn][maxn];
deque<int> mwi[maxn];

void ReFineF()
{
    int temp;

    for (int i=1; i<=n; ++i){
        top = 0;
        st[0] = 0;
        mwi[i].clear();

        for (int j=1; j<=m; ++j){
            while (top>=0 && th[i][j] <= th[i][st[top]]) --top;

            if (top>=0)
                tw[i][j] += (j-st[top]-1);
//            if (top>=0 && !th[i][st[top]]){
//                --tw[i][j];
//            }
            st[++top] = j;
        }

        top = 0;
        st[0] = m+1;

        for (int j=m; j>=1; --j){
            while (top>=0 && th[i][j] <= th[i][st[top]]) --top;

            if (top>=0)
                tw[i][j] += (st[top]-j-1);
//            if (top>=0 && !th[i][st[top]]){
//                tw[i][j]--;
//            }
            st[++top] = j;
        }
        for (int j=1; j<=m; ++j){
            h[i][j] = ii(th[i][j],tw[i][j]+1);
        }
        sort(h[i]+1, h[i]+m+1);

        for (int j=1; j<=m; ++j){
            while (!mwi[i].empty()){
                temp = mwi[i].back();
                if (h[i][temp].second <= h[i][j].second){
                    mwi[i].pop_back();
                } else break;
            }
            mwi[i].push_back(j);
        }
    }

    for (int l=n; l>=1; --l){
        for (int r=l; r<=n; ++r){
            while (!mwi[r].empty() && h[r][mwi[r].front()].first < (r-l+1))
                mwi[r].pop_front();

            if (!mwi[r].empty())
                f[l][r] = max(f[l][r], (r-l+1)*(h[r][mwi[r].front()].second));

            f[l][r] = max(f[l][r], f[l][r-1]);
            f[l][r] = max(f[l][r], f[l+1][r]);
        }
    }
}

int main()
{
    freopen("NUMTAB.INP","r",stdin);
    freopen("NUMTAB.OUT","w",stdout);

    scanf("%d %d\n",&n,&m);
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            scanf("%d ",&a[i][j]);
        }
        scanf("\n");
    }

    ///Truong hop 0-1
    memset(th, 0, sizeof(th));
    memset(tw, 0, sizeof(tw));

    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (a[i][j]==0 || a[i][j]==1){
                th[i][j] = th[i-1][j] + 1;
            } else th[i][j] = 0;
        }
    }

    ReFineF();
    /**********************/
    ///Truong hop 1-2
    memset(th, 0, sizeof(th));
    memset(tw, 0, sizeof(tw));

    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (a[i][j]==1 || a[i][j]==2){
                th[i][j] = th[i-1][j] + 1;
            } else th[i][j] = 0;
        }
    }

    ReFineF();
    /**********************/

    int k,p,q;
    scanf("%d\n",&k);
    while (k--){
        scanf("%d %d\n",&p,&q);
        printf("%d\n",f[p][q]);
    }
    return 0;
}
