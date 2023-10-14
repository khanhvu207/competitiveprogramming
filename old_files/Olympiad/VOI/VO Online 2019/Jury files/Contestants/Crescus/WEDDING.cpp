#include <bits/stdc++.h>

using namespace std;

const int N = 1500006;
int k, M, p[N], s[N], t[N], m, n;

void print(int key)
{
    if (key == 0) cout << "NO";
    else
    {
        cout << "YES\n";
        cout << m; for (int i = 0; i < m; i++) cout << ' ' << s[i]; cout << '\n';
        cout << n; for (int i = 0; i < n; i++) cout << ' ' << t[i]; cout << '\n';
    }
    exit(0);
}

bool feasible(int i)
{
    for (int k = 0; k < m; k++) if ((s[k] * t[i] - p[k * n + i]) % M) return false;
    return true;
}

void Try2(int i)
{
    for (int j = 0; j < M; j++)
    {
        t[i] = j;
        if (!feasible(i)) continue;
        if (i + 1 < n) Try2(i + 1); else print(1);
    }
}

void Try(int i)
{
    for (int j = 0; j < M; j++)
    {
        s[i] = j;
        if (i + 1 < m) Try(i + 1); else Try2(0);
    }
}

void check1(int x, int y)
{
    m = x, n = y;
    Try(0);
}

void sub1()
{
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0) check1(i, k / i), check1(k / i, i);
    print(0);
}

bool count1(int start, int jump, int Time)
{
    while (Time--)
    {
        if (p[start] == 1) return true;
        start += jump;
    }
    return false;
}

void check2(int x, int y)
{
    m = x, n = y;
    for (int i = 0; i < m; i++)
        s[i] = count1(i * n, 1, n);
    for (int i = 0; i < n; i++)
        t[i] = count1(i, n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (s[i] * t[j] - p[i * n + j] % M == 1) return;
    print(1);
}

void sub2()
{
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0) check2(i, k / i), check2(k / i, i);
    print(0);
}

void sub3()
{
    print(0);
}

int main()
{
    freopen("WEDDING.INP", "r", stdin);
    freopen("WEDDING.OUT", "w", stdout);

    scanf("%d%d", &k, &M);
    for (int i = 0; i < k; i++) scanf("%d", &p[i]);

    if (M == 2) sub2();
    else if (M <= 7) sub1();
    else sub3();

    return 0;
}
