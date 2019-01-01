#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define prev prevvvvvvvv
typedef pair<int, pair<int, int> > iii;
const int N = 2000015;
priority_queue<iii, vector<iii>, greater<iii> > heap;
int n;
bool mark[N];

struct node {
    int left, right;
    long long val;
    node() {
        left = -1;
        right = -1;
        val = 0;
    }
    node(int l, int r, int x) {
        this -> left = l;
        this -> right = r;
        this -> val = x;
    }
} a[N];

void link(int idA, int idB) {
    a[idA].right = idB;
    a[idB].left = idA;
    heap.push({max(a[idA].val, a[idB].val), {idA, idB}});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("xoaso.inp", "r", stdin);
    freopen("xoaso.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        a[i] = node(-1, -1, x);
        if (i != 0) {
            link(i - 1, i);
        }
    }

    long long res = 0;
    while (!heap.empty()) {
        int u = heap.top().second.first;
        int v = heap.top().second.second;
        if (mark[u] || mark[v]) {
            heap.pop();
            continue;
        }
        res += heap.top().first;
        node dummy = node(-1, -1, heap.top().first);
        if (dummy.val == a[u].val) {
            if (a[v].right != -1) link(u, a[v].right);
            mark[v] = true;
        } else {
            if (a[u].left != -1) link(v, a[u].left);
            mark[u] = true;
        }
    }
    cout << res;
}
