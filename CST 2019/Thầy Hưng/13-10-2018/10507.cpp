#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<char> DSU;
vector<char> g[100];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("input.in", "r", stdin);
    while (cin >> n >> m)
    {
    	DSU.clear();
    	for (char x = 'A'; x <= 'Z'; x++) g[x].clear();
    	string init;
    	cin >> init;
    	for (int i = 0; i < 3; i++) DSU.push_back(init[i]);
    	for (int i = 0; i < m; i++)
    	{
    		char a, b;
    		cin >> a >> b;
    		g[a].push_back(b);
    		g[b].push_back(a);
    	}
    	int year = 0, ct = 3;
    	bool vst[100] = {0};
    	for (int i = 0; i < (int)DSU.size(); i++)
    		vst[DSU[i]] = 1;
    	for (int t = 1; t <= 26 && ct < n; t++)
    	{
    		++year;
    		int cnt[91] = {0};
    		for (int i = 0; i < (int)DSU.size(); i++)
    			for (int j = 0; j < (int)g[DSU[i]].size(); j++)
    				cnt[g[DSU[i]][j]]++;
    		for (char x = 'A'; x <= 'Z'; x++)
    			if (!vst[x] && cnt[x] > 2) 
    				DSU.push_back(x),
    				vst[x] = 1,
    				ct++;
    	}
    	if (ct < n) 
    		cout << "THIS BRAIN NEVER WAKES UP\n";
    	else 
    		cout << "WAKE UP IN, " << year << ", YEARS\n";
    }
    return 0;
}
