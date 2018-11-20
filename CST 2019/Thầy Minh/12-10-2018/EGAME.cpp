#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int M, n, p;
int a[2015];

bool check (const vector<int> &D, const vector<int> &t)
{
    for (int i = 0; i < (int)D.size(); i++)
        if (D[i] <= t[i]) return false;
    return true;
}

void rec (int l, int r, int t, int sa, int sb)
{
    if (l == r)
    {
        cout << sa << '\n';
        cout << sb << '\n';
        exit(0);
    }
    int k = (r - l + 1) / 2, best;
    vector<int> left;
    vector<int> right;
    bool L, R;
    for (int i = 1; i <= k; i++)
    {
        left.push_back(a[l + i - 1]);
        right.push_back(a[r - i + 1]);
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        if (check(left, right))
        {
            best = i;
            L = true;
            R = false;
        } else if (check(right, left))
        {
            best = i;
            L = false;
            R = true;
        }
    }
    (t ? sb += best : sa += best);
    t = t ^ 1;
    if (L && !R) r = r - best;
        else if (!L && R) l = l + best;
    rec(l, r, t, sa, sb);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("EGAME.INP", "r", stdin);
    freopen("EGAME.OUT", "w", stdout);
    cin >> M >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    rec(0, n - 1, p, 0, 0);
    return 0;
}
