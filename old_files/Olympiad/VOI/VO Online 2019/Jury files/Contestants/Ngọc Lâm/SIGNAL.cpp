#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

typedef long double ldb;

struct student
{
    ldb x, y, s;

    student() {}
    student(ldb _x, ldb _y, ldb _s)
    {
        x = _x;
        y = _y;
        s = _s;
    }
};

int N, K;
vector<student> sts;

void init_io()
{
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void read_input()
{
    cin >> N >> K;
    sts.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> sts[i].x >> sts[i].y >> sts[i].s;
    }
}

void do_sub1()
{
    ldb sum_x = 0;
    ldb sum_y = 0;

    for (int i = 0; i < N; i++)
    {
        sum_x += sts[i].x;
        sum_y += sts[i].y;
    }

    ldb x = sum_x / N;
    ldb y = sum_y / N;

    ldb power = 0;
    for (int i = 0; i < N; i++)
    {
        ldb dist = abs(sts[i].x - x) + abs(sts[i].y - y);
        power = max(power, dist / sts[i].s);
    }

    cout << fixed << setprecision(9) << power;
}

int main()
{
    init_io();
    read_input();

    if (N == K) cout << 0;
    else if (K == 1) do_sub1();

    return 0;
}
