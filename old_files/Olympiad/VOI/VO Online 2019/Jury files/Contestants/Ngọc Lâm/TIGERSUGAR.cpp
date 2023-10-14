#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

typedef long long ll;

struct Rect
{
    ll x1, x2, y1, y2;

    Rect() {}

    Rect(ll _x1, ll _y1, ll _x2, ll _y2)
    {
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
    }
};

const int MAX_N = 100000;

int N;
Rect rects[MAX_N];

bool sub2 = true;
bool sub3 = true;

void init_io()
{
    freopen("TIGERSUGAR.INP", "r", stdin);
    freopen("TIGERSUGAR.OUT", "w", stdout);
}

void read_input()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld %lld", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);

        if (rects[i].x1 != rects[i].x2 || rects[i].y1 != rects[i].y2) sub2 = false;
        if (rects[i].x1 != rects[i].x2 || rects[i].x1 != 0 || rects[i].x2 != 0) sub3 = false;
    }
}

void do_sub3()
{
    ll sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += (rects[i].y1 + rects[i].y2) / 2;
    }

    ll y_mid = sum / N;

    ll dist = 0;

    for (int i = 0; i < N; i++)
    {
        if (rects[i].y1 <= y_mid && y_mid <= rects[i].y2) continue;
        else if (rects[i].y1 > y_mid) dist += abs(y_mid - rects[i].y1);
        else dist += abs(y_mid - rects[i].y2);
    }

    printf("%lld\n", dist);
    printf("0 %lld\n", y_mid);

    for (int i = 0; i < N; i++)
    {
        if (rects[i].y1 <= y_mid && y_mid <= rects[i].y2)
        {
            printf("0 %lld\n", (rects[i].y1 + rects[i].y2) / 2);
        }
        else if (rects[i].y1 > y_mid)
        {
            printf("0 %lld\n", rects[i].y1);
        }
        else
        {
            printf("0 %lld\n", rects[i].y2);
        }
    }
}

void do_sub2()
{
    ll x = 0;
    ll y = 0;

    for (int i = 0; i < N; i++)
    {
        x += rects[i].x1;
        y += rects[i].y1;
    }

    x /= N;
    y /= N;

    ll dist = 0;
    for (int i = 0; i < N; i++)
    {
        dist += abs(rects[i].x1 - x) + abs(rects[i].y1 - y);
    }

    printf("%lld\n", dist);
    printf("%lld %lld\n", x, y);

    for (int i = 0; i < N; i++) printf("%lld %lld\n", rects[i].x1, rects[i].y1);
}

int main()
{
    init_io();
    read_input();

    if (sub3) do_sub3();
    else if (sub2) do_sub2();

    return 0;
}
