#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const long long mod = 1e9+7;

int n;
char s[1000015];
long long base[1000015], h[1000015];

long long gethash (int l, int r)
{
	long long res=((h[r] - h[l-1]*base[r-l+1] + mod*mod)%mod);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("bcl.inp", "r", stdin);
	freopen("bcl.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> s[i];
	base[0]=1ll;
	for (int i=1; i<=1000000; i++)
		base[i]=(base[i-1]*31ll)%mod;

	for (int i=1; i<=n; i++)
		h[i]=(h[i-1]*31ll+(long long)s[i]-65ll)%mod;

	int l=1, r=n, p=0;
	while (l<=r)
	{
		if (s[l]<s[r])
		{
			cout << s[l]; ++l;
			continue;
		} else 
		if (s[r]<s[l])
		{
			cout << s[r]; --r;
			continue;
		}
		int pl=1, pr=(r-l+1)>>1;
		while (pl<=pr)
		{
			int pm=(pl+pr)>>1;
			if (gethash(l, l+pm-1)==gethash(r-pm+1, r))
			{
				p=pm;
				pl=pm+1;
			}
			else pr=pm-1;
		}
		if (s[l+p]<s[r-p])
		{
			cout << s[l]; ++l;
			continue;
		} else
		{
			cout << s[r]; --r;
			continue;
		}
	}
	return 0;
}