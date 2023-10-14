#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int n;
map<vector<int>, int> mp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("input.in", "r", stdin);
    while (cin >> n)
    {
    	if (n < 1) return 0;
    	mp.clear();
    	for (int i = 0; i < n; i++)
    	{
    		vector<int> a;
    		for (int j = 0, x; j < 5; j++) cin >> x, a.push_back(x);
    		sort(a.begin(), a.end());
    		mp[a]++;
    	}
    	int mx = 0, res = 0;
    	for (map<vector<int>, int>::iterator it = mp.begin(); it != mp.end(); it++)
    		mx = max(mx, it -> second);
    	for (map<vector<int>, int>::iterator it = mp.begin(); it != mp.end(); it++)
    		if (it -> second == mx) res++;
    	cout << mx * res << '\n';
    }
    return 0;
}
