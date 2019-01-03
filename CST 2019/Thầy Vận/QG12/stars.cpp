#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int, int> coordinates;

int n, m;
vector<coordinates> pic, sky;

bool chk(int dx, int dy) {
    for (int i = 0; i < m; ++i) {
        coordinates t = coordinates(pic[i].x + dx, pic[i].y + dy);
        if (!binary_search(sky.begin(), sky.end(), t)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("stars.inp", "r", stdin);
    freopen("stars.out", "w", stdout);
    cin >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        pic.push_back(coordinates(u, v));
    }
    cin >> n;
    for (int i = 0, u, v; i < n; ++i) {
        cin >> u >> v;
        sky.push_back(coordinates(u, v));
    }
    sort(sky.begin(), sky.end());
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            int deltax = sky[j].x - pic[i].x;
            int deltay = sky[j].y - pic[i].y;
            //cerr << deltax << ' ' << deltay << '\n';
            if (chk(deltax, deltay)) {
                cout << deltax << ' ' << deltay << '\n';
                return 0;
            }
        }
}
