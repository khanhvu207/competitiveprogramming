#include <bits/stdc++.h>
using namespace std;
const long long MOD = 2019201997;
long long n, k;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	long long ans = MOD - 48ll * n - 84ll * (k - 1ll);
	cout << ans;
}