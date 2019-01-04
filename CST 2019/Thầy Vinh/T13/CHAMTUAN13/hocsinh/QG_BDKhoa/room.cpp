#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
#define iiii pair<ii,ii>
using namespace std;

int n;
map <ii,int> mm;
int dx[8] ={0,1,1,1,0,-1,-1,-1};
int dy[8] ={1,1,0,-1,-1,-1,0,1};
map <iiii,int> magic;
string xxx;

int main()
{
    freopen("room.inp","r",stdin);
    freopen("room.out","w",stdout);
    cin >> n;
    cin >> xxx;
    int x = 0; int y = 0; int kq=0;
    //int trcx=0; int trcy=0;
    mm.clear();
    mm[ii(0,0)] = 1;
    for (int i=1; i<=n; i++)
    {
        char t; t = xxx[i-1];
        int u = x + dx[(int) t - 48];
        int v = y + dy[(int) t - 48];
        if (mm[ii(u,v)]==0)
        {
            mm[ii(u,v)]=1;
         //   cerr << u << " " << v << ": "  << mm[ii(u,v)] << '\n';
        }
        else if (magic[iiii(ii(u,v),ii(x,y))]==0) kq++;
        magic[iiii(ii(u,v),ii(x,y))] = magic[iiii(ii(x,y),ii(u,v))] = 1;
        x =u; y = v;
        u = x + dx[(int) t - 48];
        v = y + dy[(int) t - 48];
        if (mm[ii(u,v)]==0)
        {
            mm[ii(u,v)]=1;
         //   cerr << u << " " << v << ": "  << mm[ii(u,v)] << '\n';
        }
        else if (magic[iiii(ii(u,v),ii(x,y))]==0) kq++;
        magic[iiii(ii(u,v),ii(x,y))] = magic[iiii(ii(x,y),ii(u,v))] = 1;

        x =u; y = v;
    }

    cout << kq;
    return 0;
}
