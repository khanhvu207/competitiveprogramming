#include <iostream>
using namespace std;

struct node 
{
	node *bit[2];
	long long cnt;
	node()
	{
		bit[0] = bit[1] = NULL;
		cnt = 0ll;
	}
};

node *root;
const long long mod = 65536;
long long seed, mul, add, n, k, a[1050015];

long long get (long long x)
{
	long long ans = 0ll;
	node *p = root;
	for (int i = 30; i >= 0; --i)
		if (p -> bit[0] != NULL && p -> bit[0] -> cnt >= x)
		{
			ans = (ans << 1ll);
			p = p -> bit[0];
		} else if (p -> bit[1] != NULL)
		{
			if (p -> bit[0] != NULL) x -= p -> bit[0] -> cnt;
			ans = (ans << 1ll) + 1ll;
			p = p -> bit[1];
		}
	return ans;
}

void upd (long long x)
{
	node *p = root;
	for (int i = 30; i >= 0; --i)
	{
		if (p -> bit[(x >> i) & 1] == NULL)
			p -> bit[(x >> i) & 1] = new node();
		p = p -> bit[(x >> i) & 1];
		++(p -> cnt);
	}
}

void del (long long x)
{
    node *p = root;
    for (int i = 30; i >= 0; i--)
    {
        --(p -> bit[(x >> i) & 1ll] -> cnt);
        if (p -> bit[(x >> i) & 1ll] -> cnt == 0)
        {
            p -> bit[(x >> i) & 1ll] = NULL;
            return;
        }
        else p = p -> bit[(x >> i) & 1ll];
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; ++T)
	{
		root = new node();
		cin >> seed >> mul >> add >> n >> k;

		a[0] = seed % mod;
		for (int i = 1; i < n; ++i)
			a[i] = ((a[i - 1] % mod) * (mul % mod)) % mod,
			a[i] = (a[i] + (add % mod)) % mod;

		for (int i = 0; i < k; ++i) upd(a[i]);
		
		long long sum = get((k + 1) / 2);

		for (int l = 1, r = k; r < n; ++l, ++r)
		{
			del(a[l - 1]);
			upd(a[r]);
			sum += get((k + 1) / 2);
		}
		cout << "Case #" << T << ": " << sum << '\n';
	}
}