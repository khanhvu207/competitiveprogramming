#include <iostream>
#include <cstdio>
using namespace std;
const int n = 60015;
struct st
{
    int lazy, val;
};
st node[4 * n];
int c, s, r;

void down (int id)
{
    int t = node[id].lazy;
    node[id * 2].lazy += t;
    node[id * 2 + 1].lazy += t;
    node[id].lazy = 0;
}

void update (int id, int tl, int tr, int L, int R, int x)
{
    if (tl > R || tr < L) return;
    if (L <= tl && tr <= R) {
        node[id].lazy += x;
        return;
    }
    int tm = (tl + tr) / 2;
    down(id);
    update(id * 2, tl, tm, L, R, x);
    update(id * 2 + 1, tm + 1, tr, L, R, x);
    node[id].val = max(node[id * 2].val + node[id * 2].lazy, node[id * 2 + 1].val + node[id * 2 + 1].lazy);
}

int get (int id, int tl, int tr, int L, int R)
{
    if (tl > R || tr < L) return 0;
    if (L <= tl && tr <= R) {
        return node[id].val + node[id].lazy;
    }
    int tm = (tl + tr) / 2;
    node[id].val += node[id].lazy;
    down(id);
    return max(get(id * 2, tl, tm, L, R), get(id * 2 + 1, tm + 1, tr, L, R));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("kol.inp", "r", stdin);
    freopen("kol.out", "w", stdout);

    cin >> c >> s >> r;
    for (int i = 0, L, R, seat; i < r; ++i)
    {
        cin >> L >> R >> seat;
        int k = get(1, 1, n, L, R - 1);
        if (s - k < seat)
            cout << "N\n";
        else
            cout << "T\n",
            update(1, 1, n, L, R - 1, seat);
    }
}
