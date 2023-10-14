#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("11824.INP", "r", stdin);
    freopen("11824.OUT", "w", stdout);
    cin >> t;
    while (t--)
    {
    	vector<int> L;
    	while (cin >> n)
    	{
    		if (n < 1) break;
    		L.push_back(n);
    	}
    	sort(L.begin(), L.end());
    	reverse(L.begin(), L.end());
    	int t = 5000000 / 2, cur = 0, flag = 1;
    	for (int i = 0; i < (int)L.size(); i++)
    	{
    		int sum = L[i];
    		for (int j = 1; j <= i; j++)
    			sum *= L[i];
    		if (sum + cur > t)
    		{
    			flag = 0;
    			break;
    		} else cur += sum;
    	}
    	if (flag) 
    		cout << cur * 2 << '\n';
    	else
    		cout << "Too expensive\n";
    }
    return 0;
}
