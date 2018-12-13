#include <iostream>
using namespace std;

struct Trie
{
	Trie *child[26];
	int cnt;
	Trie()
	{
		for (int i = 0; i < 26; ++i) 
			child[i] = NULL;
		cnt = 0;
	}
};

int n, res = 0;
string str;
Trie *root = new Trie();

void TrieInsert (const string &s)
{
	int sum = 0;
	int m = (int)s.size();
	Trie *p = root;

	for (int i = 0; i < m; ++i)
	{
		int nxt = s[i] - 'a';
		if (p->child[nxt] == NULL)
			p->child[nxt] = new Trie();
		sum += p->cnt;
		p = p->child[nxt];
	}
	p->cnt = 1;
	++sum;
	res = max(res, sum);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		TrieInsert(str);
	}
	cout << res;
}