#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int n, a[1000015];
set<int> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("rbech.inp", "r", stdin);
    freopen("rbech.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int res=1;
    s.insert(a[1]+1);
    for (int i=2; i<=n; i++)
        if (s.find(i-a[i])!=s.end())
        {
            res=max(res, i);
            s.insert(i+a[i]);
        }
    cout << res;
    return 0;
}
/**
    j-a[j]=a[i]+i
    update (j+a[j]) if true
**/
