#include <iostream>
using namespace std;
const long long mod = 1337377;

struct TrieNode
{
	TrieNode *child[26];
	int cnt;
	TrieNode()
	{
		for (int i = 0; i < 26; ++i)
			child[i] = NULL;
		cnt = 0;
	}
};

int n;
long long dp[300015];
string S;
TrieNode *root = new TrieNode();

void TrieInsert (const string &s)
{
	TrieNode *p = root;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		int nxt = s[i] - 'a';
		if (p->child[nxt] == NULL)
			p->child[nxt] = new TrieNode();
		p = p->child[nxt];
	}
	p->cnt++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> S;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		TrieInsert(str);
	}
	int m = S.size();
	dp[m] = 1ll;
	for (int i = m - 1, j; i >= 0; --i)
	{
		long long sum = 0;
		TrieNode *p = root;
		for (j = i; j < m; ++j)
		{
			int nxt = S[j] - 'a';
			if (p->child[nxt] == NULL) break;
			if (p->cnt > 0)
				sum = (sum + dp[j]) % mod;
			p = p->child[nxt];
		}
		if (p->cnt > 0)
			sum = (sum + dp[j]) % mod;
		dp[i] = sum % mod;
	}
	cout << dp[0];
}