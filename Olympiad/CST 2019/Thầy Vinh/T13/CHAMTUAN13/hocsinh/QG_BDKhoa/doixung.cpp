#include <bits/stdc++.h>

using namespace std;

int n;
char a[5005];
int f[5005][5005];

int main()
{
    freopen("doixung.inp","r",stdin);
    freopen("doixung.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    memset(f,0,sizeof(f));
    for (int i=1; i<=n; i++) f[i][i] = 1;
    for (int k=2; k<=n; k++)
        for (int i=1; i<=n-k+1; i++)
        {
            int j = i + k-1;
            if (a[i] == a[j]) f[i][j] = f[i+1][j-1] + 2;
            f[i][j] = max(f[i][j],max(f[i+1][j],f[i][j-1]));
        }
    cout << n-f[1][n];
    return 0;
}
