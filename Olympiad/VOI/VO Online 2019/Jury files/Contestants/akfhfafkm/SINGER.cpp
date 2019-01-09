#include<bits/stdc++.h>
#define maxn 6500
using namespace std;

int n, d, t, F[maxn];

bool check(int u)
{
    int dem = 0;

    int cur = 1;

    for(int i=n-1;i>=0;i--)
    {
        if((u >> i) & 1)
        {
            if(i == n - 1) ++cur;
            else
            {
                if(!((u >> (i + 1)) & 1))
                {
                    ++cur;
                }
                else
                {
                    if(cur >= d) dem = dem + cur - d + 1;
                    cur = 2;
                }
            }
        }
        else
        {
            if(i == n - 1) ++cur;
            else
            {
                if((u >> (i + 1)) & 1)
                {
                    ++cur;
                }
                else
                {
                    if(cur >= d) dem = dem + cur - d + 1;
                    cur = 2;
                }
            }
        }
    }

    if(cur >= d) dem = dem + cur - d + 1;

    return dem == t;
}

int main()
{
    freopen("SINGER.inp","r",stdin);
    freopen("SINGER.out","w",stdout);

    cin >> n >> d >> t;

    int dem = 0;

    for(int i=0;i<(1<<n);i++)
    {
        if(check(i))
        {
            ++dem;
        }
    }

    cout << dem;
}
