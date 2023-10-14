#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

typedef pair<ll, char> pic;

int N, M;
vector<ll> P, Q;

void init_io()
{
    freopen("VECTOR.INP", "r", stdin);
    freopen("VECTOR.OUT", "w", stdout);
}

void read_input()
{
    scanf("%d", &N);
    P.resize(N);
    for (int i = 0; i < N; i++) scanf("%lld", &P[i]);

    scanf("%d", &M);
    Q.resize(M);
    for (int i = 0; i < M; i++) scanf("%lld", &Q[i]);
}

ll calculate_pi(vector<ll> v)
{
    ll prod = 1;
    for (int i = 0; i < v.size(); i++) prod *= v[i];

    return prod;
}

void print_result(vector<pic> result)
{
    printf("%d\n", result.size());

    for (int i = 0; i < result.size(); i++)
    {
        printf("%lld %c\n", result[i].first, result[i].second);
    }
}

void solve()
{
    ll A = calculate_pi(P);
    ll B = calculate_pi(Q);

    vector<pic> steps;

    steps.push_back(pic(B, 'D'));
    steps.push_back(pic(B, 'W'));

    A *= B;

    ll last = 1;
    for (ll i = 2; i <= sqrt(A); i++)
    {
        if (A % (i*i) == 0) last = i;
    }

    steps.push_back(pic(last, 'L'));

    print_result(steps);
}

int main()
{
    init_io();
    read_input();
    solve();

    return 0;
}
