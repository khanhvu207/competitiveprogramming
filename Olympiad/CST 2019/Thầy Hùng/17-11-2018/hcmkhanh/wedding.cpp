#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, table;
bool vst[4015];
vector<int> g[4015], block[4015];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("wedding.inp", "r", stdin);
    freopen("wedding.out", "w", stdout);
    cin >> n;
    n*=2;
    for (int i=1, x; i<=n; ++i)
    {
        cin >> x;
        table=max(table, x+1);
        for (int j=0, v; j<x; ++j)
            cin >> v,
            g[i].push_back(v);
        g[i].push_back(i);
    }
    int ptr=1;
    for (int opponent=1; opponent<=n; ++opponent)
    {
        while (!g[opponent].empty())
        {
            int x=*(g[opponent].end()-1);
            g[opponent].pop_back();
            if (!vst[x]) block[ptr++].push_back(x), vst[x]=1;
            if (ptr>table) ptr=1;
        }
    }
    for (int i=1; i<=table; ++i)
        for (int j=0; j<(int)block[i].size(); ++j)
            cout << block[i][j] << ' ';
}
