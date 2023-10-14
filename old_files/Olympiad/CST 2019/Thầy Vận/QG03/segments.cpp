#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, res[100015];
pair<pair<int, int>, int> seg[100015];
stack<pair<pair<int, int>, int> > st;

bool cmp (const pair<pair<int, int>, int> &l, const pair<pair<int, int>, int> &r)
{
    if (l.first.first==r.first.first)
        return l.first.second>r.first.second;
    else
        return l.first.first<r.first.first;
}

int main() {
    freopen("segments.inp", "r", stdin);
    freopen("segments.out", "w", stdout);
    cin>>n;
    for (int i=0, x, y; i<n; i++)
        cin>>x>>y, seg[i]={{x, y}, i+1};
    sort(seg, seg+n, cmp);
    for (int i=0; i<n; i++)
    {
        pair<pair<int, int>, int> t;
        while (!st.empty())
        {
            t = st.top();
            if(t.first.first<=seg[i].first.first && seg[i].first.second<=t.first.second) break;
            st.pop();
        }
        if (st.empty())
            res[seg[i].second]=0;
        else
            res[seg[i].second]=st.top().second;
        st.push(seg[i]);
    }
    for (int i=1; i<=n; i++)
        cout<<res[i]<<'\n';
    return 0;
}
