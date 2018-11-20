#include <iostream>
using namespace std;

int n, a[2015], p[2015], dp[2015][2015], h[2015][2015];

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
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	for (int i=1; i<=n; ++i)
		p[i]=p[i-1]+a[i];
	for (int i=1; i<=n; ++i)
		dp[i][i]=0,
		h[i][i]=i;
	for (int d=1; d<=n-1; ++d)
		for (int i=1; i<=n-d; ++i)
			dp[i][i+d]=optimize(i, i+d);
	cout << dp[1][n];
	return 0;
}