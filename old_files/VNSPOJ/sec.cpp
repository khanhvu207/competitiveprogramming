#include <iostream>
using namespace std;

struct TrieNode
{
	TrieNode *child[2];
	long long cnt, flag;
	TrieNode()
	{
		for (int i = 0; i < 2; ++i)
			child[i] = NULL;
		cnt = flag = 0;
	}
};
TrieNode *root = new TrieNode();
int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0, k; i < n; ++i)
	{
		cin >> k;
		TrieNode *p = root;
		for (int j = 0, x; j < k; ++j) 
		{
			cin >> x;
			if (p->child[x] == NULL)
				p->child[x] = new TrieNode();
			p = p->child[x];
			++p->cnt;
		}
		++p->flag;
	}

	for (int i = 0, k; i < m; ++i)
	{
		cin >> k;
		TrieNode *p = root;
		bool t = true;
		long long res = 0;
		for (int j = 0, x; j < k; ++j)
		{
			cin >> x;
			if (!t) continue;
			if (p->child[x] == NULL)
			{
				t = false;
				continue;
			}
			p = p->child[x];
			if (j != k - 1)
				res += p->flag;
			else
				res += p->cnt;
		}
		cout << res << '\n';
	}
}