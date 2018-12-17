#include <iostream>
#include <cstdio>
using namespace std;
#define val first
#define lazy second
#define prev akjhdfak
const int N = 100015;

pair<int, int> st[4 * N];
int n, res, prev[N];

void pushdown(int id)
{
    int t = st[id].lazy;
    st[id << 1].val += t;
    st[id << 1].lazy += t;
    st[id << 1 | 1].val += t;
    st[id << 1 | 1].lazy += t;
    st[id].lazy = 0;
}

void update(int id, int tl, int tr, int L, int R)
{
    if (tl > R || tr < L) return;
    if (L <= tl && tr <= R)
    {
        ++st[id].val;
        ++st[id].lazy;
        return;
    }
    int tm = (tl + tr) >> 1;
    pushdown(id);
    update(id << 1, tl, tm, L, R);
    update(id << 1 | 1, tm + 1, tr, L, R);
    st[id].val = max(st[id << 1].val, st[id << 1 | 1].val);
}

int get(int id, int tl, int tr, int L, int R)
{
    if (tl > R || tr < L) return 0;
    if (L <= tl && tr <= R) return st[id].val;
    int tm = (tl + tr) >> 1;
    pushdown(id);
    return max(get(id << 1, tl, tm, L, R), get(id << 1 | 1, tm + 1, tr, L, R));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("runghoa.inp", "r", stdin);
    freopen("runghoa.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int L, R;
        cin >> L >> R;
        int a = max(prev[L], get(1, 1, n, L, L));
        int b = max(prev[R], get(1, 1, n, R, R));
        res = a + b - prev[L] - prev[R];
        cout << res << '\n';
        prev[L] = a, prev[R] = b;
        if (L + 1 < R)
            update(1, 1, n, L, R);
    }
}
