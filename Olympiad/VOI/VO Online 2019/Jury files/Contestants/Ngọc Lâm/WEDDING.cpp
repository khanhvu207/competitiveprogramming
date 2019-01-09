#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const ll MAX_K = 1500000;

int K, m, n;
ll MOD;
ll P[MAX_K];

vector<ll> S, T;

bool found_result = false;

void init_io()
{
    freopen("WEDDING.INP", "r", stdin);
    freopen("WEDDING.OUT", "w", stdout);
}

void read_input()
{
    scanf("%d %lld", &K, &MOD);
    for (ll i = 0; i < K; i++) scanf("%lld", &P[i]);
}

void check()
{
    for (int j = 0; j < n; j++)
    {
        T[j] = -1;

        for (ll k = 0; k < MOD; k++)
        {
            bool f = true;

            for (int i = 0; i < m; i++)
            {
                ll sum = S[i] * k - P[i*n + j];
                if (sum % MOD != 0)
                {
                    f = false;
                    break;
                }
            }

            if (f)
            {
                T[j] = k;
                break;
            }
        }

        if (T[j] == -1) return;
    }

    found_result = true;
}

void backtrack(int pos)
{
    for (ll i = 0; i < MOD && !found_result; i++)
    {
        if (found_result) return;

        S[pos] = i;
        if (pos == m - 1) check();
        else backtrack(pos + 1);

        if (found_result) return;
    }
}

void do_sub1()
{
    for (int i = 2; i <= sqrt(K); i++)
    {
        if (K % i == 0)
        {
            m = i;
            n = K / m;

            S.assign(m, 0);
            T.assign(n, 0);

            backtrack(0);

            if (found_result) break;
        }
    }
}

void check2()
{
    for (int i = 0; i < m; i++)
    {
        S[i] = -1;

        for (ll k = 0; k < MOD; k++)
        {
            bool ok = true;

            for (int j = 0; j < n; j++)
            {
                if ((k * T[j] - P[i*n + j]) % MOD != 0)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                S[i] = k;
                break;
            }
        }

        if (S[i] == -1) return;
    }

    found_result = true;
}

void do_sub2()
{
    for (int i = 2; i <= sqrt(K) + 2; i++)
    {
        if (K % i == 0)
        {
            m = K / i;
            n = i;

            S.assign(m, 0);
            T.assign(n, 1);

            check2();

            if (found_result) return;
        }
    }
}

int main()
{
    init_io();
    read_input();

    if (MOD == 2) do_sub2();
    else if (K <= 20) do_sub1();

    if (found_result)
    {
        printf("YES\n");

        printf("%d ", S.size());
        for (ll s : S) printf("%lld ", s);

        printf("\n");

        printf("%d ", T.size());
        for (ll t : T) printf("%lld ", t);
    }
    else printf("NO");

    return 0;
}
