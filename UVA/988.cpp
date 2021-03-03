#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
bool flag = true;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	while (cin >> n)
	{
		vector<int> c(n + 5, 0);
		c[0] = 1;
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			int k; cin >> k;
			if (k == 0)
			{
				res += c[i];
				continue;
			}
			while (k--)
			{
				int u; cin >> u;
				c[u] += c[i];
			}
		}
		if (!flag) cout << '\n';
		cout << res << '\n';
		flag = false;
	}
}