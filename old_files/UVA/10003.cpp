#include <iostream>
#include <cstring>
using namespace std;

int n, x, a[55], b[55], p[55], dp[55][55], h[55][55];

int optimize (int l, int r)
{
	int tmp=1e9, sum=p[r]-p[l-1];
	//Knuth's optimization
	for (int k=h[l][r-1]; k<=h[l+1][r]; ++k)
		if (dp[l][k-1]+dp[k][r]+sum<=tmp)
		{
			tmp=dp[l][k-1]+dp[k][r]+sum;
			h[l][r]=k;
		}
	dp[l][r]=tmp;
	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> x)
	{
		if (x<1) return 0;
		memset(dp, 0, sizeof dp);
		memset(h, 0, sizeof h);
		cin >> n;
		for (int i=1; i<=n; ++i)
			cin >> b[i];
		
		a[1]=b[1];
		for (int i=2; i<=n+1; ++i)
			if (i>n)
				a[i]=x-b[i-1];
			else
				a[i]=b[i]-b[i-1];
		++n;

		for (int i=1; i<=n; ++i)
			p[i]=p[i-1]+a[i];
		
		for (int i=1; i<=n; ++i)
			dp[i][i]=0,
			h[i][i]=i;
		
		for (int d=1; d<=n-1; ++d)
			for (int i=1; i<=n-d; ++i)
				dp[i][i+d]=optimize(i, i+d);
		
		cout << "The minimum cutting is " << dp[1][n] << ".\n";
	}
	return 0;
}