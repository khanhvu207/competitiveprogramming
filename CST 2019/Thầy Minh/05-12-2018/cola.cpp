#include <iostream>
#include <cstdio>
using namespace std;

string s;
int n, m, k;
int a[111], b[111];

void Input()
{
    cin >> n >> m >> k;
    cin >> s;
    for (int i=0; i<m; ++i) cin >> b[i], a[i]=k;
}

void Solve()
{
    for (int i=0; i<n; ++i)
        if (s[i]=='E')
        {
            int t=-1;
            for (int j=0; j<m; ++j)
                if (a[j]>0&&(t==-1||a[j]<a[t]||(a[j]==a[t]&&b[j]<b[t]))) t=j;
            --a[t];
            cout << t+1 << ' ';
        } else
        {
            int t=-1;
            for (int j=0; j<m; ++j)
                if (a[j]>0&&(t==-1||a[j]>a[t]||(a[j]==a[t]&&b[j]<b[t]))) t=j;
            --a[t];
            cout << t+1 << ' ';
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("cola.inp", "r", stdin);
    freopen("cola.out", "w", stdout);
    Input();
    Solve();
}
