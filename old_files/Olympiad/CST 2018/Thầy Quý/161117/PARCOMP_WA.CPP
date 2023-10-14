/*
	12/20 đ
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

vector<int> a[2001], tmp;
vector<int> lt;
stack<int> st;
bool fre[2001];
int m,n,ansT,ansP;

void dfs(int u, int d){
    fre[u] = false;
    if (d > ansT) ansT = d;
    for (int i = 0; i < a[u].size(); i++)
        if (fre[a[u][i]]) dfs(a[u][i], d+1);
    fre[u] = true;
}

int main()
{
    freopen("PARCOMP.INP","r",stdin);
    freopen("PARCOMP.OUT","w",stdout);

    cin >> n >> m;
    while (m--)
    {
        int u,v; cin >> u >> v;
        a[u].push_back(v);
    }

    for (int i = 1; i<=n; i++) fre[i] = true;
    for (int i = 1; i<=n; i++) dfs(i,1);

    int t = n-ansT;
    int ansP = 1 + (t / ansT);
    if (t % ansT) ansP++;

    printf("%d %d\n", ansT, ansP);
    return 0;
}
