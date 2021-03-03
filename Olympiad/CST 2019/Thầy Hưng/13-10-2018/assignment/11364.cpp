#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
int t, n;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("11364.INP", "r", stdin);
    freopen("11364.OUT", "w", stdout);
    cin >> t;
    while (t--)
    {
    	cin >> n;
    	int l = 1000, r = -1000;
    	for (int i = 0, x; i < n; i++)
    		cin >> x,
    			l = min(l, x),
    			r = max(r, x);
    	cout << (r - l) * 2 << '\n';
    }
    return 0;
}