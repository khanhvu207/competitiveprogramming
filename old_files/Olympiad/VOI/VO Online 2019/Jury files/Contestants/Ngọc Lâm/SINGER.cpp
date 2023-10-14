#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll N, D, T;

ll result = 0;

vector<int> notes_s1;

void init_io()
{
    freopen("SINGER.INP", "r", stdin);
    freopen("SINGER.OUT", "w", stdout);
}

void read_input()
{
    scanf("%lld %lld %lld", &N, &D, &T);
}

void check()
{
    int ok = 0;

    for (int i = 0; i <= N - D + 1; i++)
    {
        int min_note = notes_s1[i];
        int max_note = notes_s1[i];

        bool valid = true;

        for (int j = i; j < i + D && valid; j++)
        {
            min_note = min(min_note, notes_s1[j]);
            max_note = max(max_note, notes_s1[j]);

            if (abs(max_note - min_note) > 1) valid = false;
        }

        if (valid) ok++;
        if (ok > T) return;
    }

    if (ok == T)
    {
        result = (result + 1) % MOD;
    }
}

void backtrack(int i)
{
    for (int j = notes_s1[i - 1] - 1; j <= notes_s1[i - 1] + 1; j += 2)
    {
        notes_s1[i] = j;

        if (i == N) check();
        else backtrack(i + 1);
    }
}

void do_sub1()
{
    notes_s1.resize(N + 1);
    notes_s1[0] = 0;
    backtrack(1);
}

int main()
{
    init_io();
    read_input();

    do_sub1();

    printf("%lld", result % MOD);

    return 0;
}
