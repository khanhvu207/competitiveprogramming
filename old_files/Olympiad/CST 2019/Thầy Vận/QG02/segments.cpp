#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, id[100015], bit[100015], res[100015];
vector<int> c;
pair<pair<int, int>, int> seg[100015];

bool cmp (const pair<pair<int, int>, int> &l, const pair<pair<int, int>, int> &r)
{
    if (l.first.first==r.first.first)
        return l.first.second>r.first.second;
    else
        return l.first.first<r.first.first;
}

int get (int x)
{
    int res=-1;
    for(; x<=100001; x=x|(x+1))
        res=max(res, bit[x]);
    return res;
}

void update (int x, int val)
{
    for (; x>=0; x=(x&(x+1))-1)
        bit[x]=max(bit[x], val);
}

int main() {
    freopen("segments.inp", "r", stdin);
    freopen("segments.out", "w", stdout);
    cin>>n;
    for (int i=0, x, y; i<n; i++)
        cin>>x>>y, seg[i]={{x, y}, i},
        c.push_back(x), c.push_back(y);
    sort(c.begin(), c.end());
    sort(seg, seg+n);
    for (int i=0; i<n; i++) id[i]=seg[i].second;
    for (int i=0; i<=100000; i++) bit[i]=-1;
    for (int i=0; i<n; i++)
    {
        int x=get(lower_bound(c.begin(), c.end(), seg[i].first.second)-c.begin()+1);
        res[id[i]]=(x<0?-1:id[x]);
        update(lower_bound(c.begin(), c.end(), seg[i].first.second)-c.begin()+1, i);
    }
    for (int i=0; i<n; i++)
        cout<<res[i]+1<<'\n';
    return 0;
}
