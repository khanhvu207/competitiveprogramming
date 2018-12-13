#include <iostream>
using namespace std;

struct node
{
	node *bit[2];
	int cnt;
	node()
	{
		bit[0] = bit[1] = NULL;
		cnt = 0;
	}
};

node *root = new node();
int n, q, flip[35];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;
	for (int i = 0, x; i < n; ++i)
	{
		cin >> x;
		node *p = root;
		for (int j = 30; j >= 0; --j)
		{
			bool nxt = x & (1 << j);
			if (p -> bit[nxt] == NULL)
				p -> bit[nxt] = new node();
			++(p -> cnt);
			p = p -> bit[nxt];
		}
		++(p -> cnt);
	}

	while (q--)
	{
		string type;
		cin >> type;
		if (type == "XOR")
		{
			int a; cin >> a;
			for (int i = 30; i >= 0; --i)
				if (a & (1 << i)) ++flip[i];
		} else
		{
			int a; cin >> a;
			long long res = 0;

			a = n - a + 1;
			node *p = root;
			for (int i = 30; i >= 0; --i)
			{
				if (p -> bit[0 ^ (flip[i] & 1)] != NULL && p -> bit[0 ^ (flip[i] & 1)] -> cnt >= a)
				{
					res = (res << 1ll);
					p = p -> bit[0 ^ (flip[i] & 1)];
				} else if (p -> bit[1 ^ (flip[i] & 1)] != NULL)
				{
					if (p -> bit[0 ^ (flip[i] & 1)] != NULL) a -= (p -> bit[0 ^ (flip[i] & 1)] -> cnt);
					res = (res << 1ll) | 1ll;
					p = p -> bit[1 ^ (flip[i] & 1)];
				}
			}
			cout << res << '\n';
		}
	}
}