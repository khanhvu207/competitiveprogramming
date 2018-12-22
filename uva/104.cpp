#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
int n;
double f[25][25][25];
int path[25][25][25];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	while (cin >> n)
	{
		memset(f, 0, sizeof f);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				path[i][j][0] = i;
				if (i != j)
					cin >> f[i][j][0];
				else
					f[i][j][0] = 1.0;
			}
		for (int steps = 1; steps < n; ++steps)
			for (int k = 0; k < n; ++k)
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
					{
						double tmp = f[i][k][steps - 1] * f[k][j][0];
						if (tmp > f[i][j][steps])
						{
							f[i][j][steps] = tmp;
							path[i][j][steps] = k;
						}
					}
		bool flag = false;
		for (int steps = 1; steps < n; ++steps)
		{
			for (int i = 0; i < n; ++i)
				if (f[i][i][steps] > 1.01)
				{
					int seq[steps];
					seq[steps] = path[i][i][steps];
					for (int j = steps - 1; j >= 0; --j)
						seq[j] = path[i][seq[j + 1]][j];
					for (int j = 0; j <= steps; ++j)
						cout << seq[j] + 1 << ' ';
					cout << seq[0] + 1 << '\n';
					flag = true;
					break;
				}
			if (flag) break;
		}
		if (!flag)
			cout << "no arbitrage sequence exists\n";
	}
}