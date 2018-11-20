#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("11933.INP", "r", stdin);
    freopen("11933.OUT", "w", stdout);
    while (cin >> n)
    {
    	if (n < 1) return 0;
    	int k = 0;
    	long long a = 0, b = 0;
    	for (int i = 0; i < 32; i++)
    		if (n & (1 << i))
    		{
    			if (++k & 1) a |= (1 << i);
    				else b |= (1 << i);
    		}
    	cout << a << ' ' << b << '\n';
    }
    return 0;
}
