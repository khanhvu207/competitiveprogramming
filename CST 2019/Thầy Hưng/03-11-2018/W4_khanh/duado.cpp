#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, m, lowest, id, dest[300015];
long long res = 0;
bool finish[300015];
stack<int> st;
vector<pair<int, int> > ev;

int main()
{
    freopen("duado.inp", "r", stdin);
    freopen("duado.out", "w", stdout);
    cin >> n >> m;
    for (int i=0, l, r; i<n; i++)
        cin >> l >> r,
        ev.push_back(make_pair(l, (i+1))),
        ev.push_back(make_pair(r, -(i+1))),
        dest[i+1]=r;
    sort(ev.begin(), ev.end());
    lowest=1000000001;
    for (int i=0; i<(int)ev.size(); i++)
    {
        res+=(ev[i].first-(i<1?0:ev[i-1].first));
        if (ev[i].second<0)
        {
            if (finish[-ev[i].second]) continue;
            if (ev[i].first<lowest)
                lowest=ev[i].first,
                id=-ev[i].second;
        } else
        {
            if (dest[ev[i].second]>ev[i].first)
            {
                finish[ev[i].second]=1;
                continue;
            }
            if (ev[i].second==id)
            {
                res+=(ev[i].first-lowest)*2;
                while (!st.empty())
                    finish[st.top()]=1,
                    st.pop();
                lowest=1000000001;
            } else
                st.push(ev[i].second);
        }
    }
    res+=(m-ev[(int)ev.size()-1].first);
    cout << res;
    return 0;
}
