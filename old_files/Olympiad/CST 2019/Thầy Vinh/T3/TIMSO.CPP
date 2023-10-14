#include <iostream>
#include <cstdio>

#define maxn 100001

using namespace std;
int n;
short a[maxn];

void nEgAtiVe()
{
    for (int i=n-1; i>=0; --i){
        if (a[i]+1 <= 9){
            ++a[i];

            printf("-");
            for (int j=0; j<n; ++j)
                printf("%d",a[j]);
            printf("\n");
            return;
        }
    }
    printf("%d",-1);
    for (int j=0; j<n; ++j)
        printf("%d",a[j]);
    printf("\n");
    return;
}

void pOsItiVe()
{
    int hold = 1 + a[n-1];
    for (int i=n-2; i>=0; --i){
        if (a[i] && hold + 1 <= (n-i-1)*9){
            --a[i];
            ++hold;

            for (int j=i+1; j<n; ++j){
                a[j] = min(9,hold);
                hold -= a[j];
            }

            bool flag = false;

            for (int j=0; j<n; ++j){
                if (a[j]!=0) flag = true;
                if (a[j] == 0 && !flag)
                    continue;
                printf("%d",a[j]);
            }
            printf("\n");
            return;
        }
        hold += a[i];
    }

    if (hold - a[0] <= (n-1)*9){
        printf("-%d",a[0]);
        for (int j=1; j<n; ++j){
            a[j] = min(9,hold);
            hold -= a[j];

            printf("%d",a[j]);
        }
        printf("\n");
        return;
    }

    if (a[0] == 9){
        printf("%d%d",-1,a[0]);
    } else{
        printf("%d",-(a[0]+1));
    }

    for (int j=1; j<n; ++j)
        printf("%d",a[j]);
    printf("\n");
    return;
}
int main()
{
    freopen("TIMSO.INP","r",stdin);
    freopen("TIMSO.OUT","w",stdout);

    int T = 0; scanf("%d\n",&T);
    char c;
    bool negative;

    while (T--){
        c = getchar();
        negative = false;
        if (c == '-'){
            negative = true;
            c = getchar();
        }

        n = 0;
        a[n++] = c - '0';
        while (scanf("%c",&c)==1){
            if ('0'>c||'9'<c) break;
            a[n++] = c - '0';
        }

        if (negative){
            nEgAtiVe();
        } else
            pOsItiVe();
    }
    return 0;
}
