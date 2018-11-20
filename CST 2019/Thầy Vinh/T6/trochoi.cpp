#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int n, k, cnt[500015];
vector<int> a;
map<string, int> m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("trochoi.inp", "r", stdin);
    freopen("trochoi.out", "w", stdout);
    m["SN"]=0;
    m["NS"]=1;
    cin >> n >> k;
    for (int i=0; i<n; ++i)
    {
        string magnet; cin >> magnet;
        int x=m[magnet];
        if (!a.empty()&&x==a[(int)a.size()-1])
            cnt[(int)a.size()-1]++;
        else
            a.push_back(x),
            cnt[(int)a.size()-1]++;
    }
    int l=0, r=0, sum=cnt[0], res=1e9;
    while (r<(int)a.size())
    {
        while (sum>k&&l+1<=r) sum-=cnt[l++];
        if ((l==0||r==(int)a.size()-1)&&sum==k)
        {
            res=min(res, (r-l+1)/2);
        } else if (l>0&&r<(int)a.size()-1&&((r-l+1)&1)&&sum==k)
            res=min(res, (r-l+1)/2);
        sum+=cnt[++r];
    }
    cout << res;
    return 0;
}
