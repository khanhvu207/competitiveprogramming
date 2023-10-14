#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

char c[10][15], res[15][15];
vector<int> s[15];
int v[10];
bool used[15];

void rec(int x, int y)
{
    if (x == 5) {
        v[0] = s[0][0] + s[1][1] + s[2][0] + s[3][0];
        v[1] = s[0][0] + s[1][2] + s[2][1] + s[3][3];
        v[2] = s[1][0] + s[1][1] + s[1][2] + s[1][3];
        v[3] = s[3][0] + s[3][1] + s[3][2] + s[3][3];
        v[4] = s[1][0] + s[2][0] + s[3][1] + s[4][0];
        v[5] = s[1][3] + s[2][1] + s[3][2] + s[4][0];
        if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[3] == v[4] && v[4] == v[5]) {
            cout << "...." << (char)(s[0][0] + 'A' - 1) << "....\n";
            cout << '.' << (char)(s[1][0] + 'A' - 1) << '.' << (char)(s[1][1] + 'A' - 1) << '.' << (char)(s[1][2] + 'A' - 1) << '.' << (char)(s[1][3] + 'A' - 1) << ".\n";
            cout << ".." << (char)(s[2][0] + 'A' - 1) << "..." << (char)(s[2][1] + 'A' - 1) << "..\n";
            cout << '.' << (char)(s[3][0] + 'A' - 1) << '.' << (char)(s[3][1] + 'A' - 1) << '.' << (char)(s[3][2] + 'A' - 1) << '.' << (char)(s[3][3] + 'A' - 1) << ".\n";
            cout << "...." << (char)(s[4][0] + 'A' - 1) << "....\n";
            exit(0);
        }
        //exit(0);
        return;
    }
    if (s[x][y] != 0) {
        if (y == (int)s[x].size() - 1)
            y = 0, x = x + 1;
        else
            y = y + 1;
        rec(x, y);
    } else {
        for (int num = 1; num <= 12; ++num)
            if (!used[num]) {
                s[x][y] = num;
                int tx = x;
                int ty = y;
                if (ty == (int)s[x].size() - 1)
                    ty = 0, tx = tx + 1;
                else
                    ty = ty + 1;
                used[num] = true;
                rec(tx, ty);
                s[x][y] = 0;
                used[num] = false;
            }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("star.inp", "r", stdin);
    freopen("star.out", "w", stdout);
    for (int i = 0; i < 5; ++i) {
        string line;
        getline(cin, line);
        for (int j = 0; j < 9; ++j)
            if (line[j] != '.') {
                if (line[j] == 'x')
                    s[i].push_back(0);
                else {
                    s[i].push_back(line[j] - 'A' + 1);
                    used[line[j] - 'A' + 1] = true;
                }
            }
    }
    rec(0, 0);
}
