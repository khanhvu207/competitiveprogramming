#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

const int dirX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dirY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int x0, y0, x1, y1, n;
map <pair <int, int>, bool> check;
queue <pair <pair <int, int>, int>> q;

int main() {
    freopen("king.inp", "r", stdin);
    freopen("king.out", "w", stdout);
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    for (int r, x, y; n--;) {
        cin >> r >> x >> y;
        for (; x <= y; ++x)
            check[{r, x}] = true;
    }
    q.push({{x0, y0}, 0});
    check[{x0, y0}] = false;
    while (!q.empty()) {
        int X = q.front().first.first;
        int Y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if (X == x1 && Y == y1) {
            cout << d; return 0;
        }
        for (int i = 0; i < 8; ++i) {
            int x = X + dirX[i];
            int y = Y + dirY[i];
            if (check[{x, y}])
                check[{x, y}] = false,
                q.push({{x, y}, d + 1});
        }
    }
    cout << -1;
}
