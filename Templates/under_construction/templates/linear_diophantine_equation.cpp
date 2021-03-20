#include <bits/stdc++.h>
using namespace std;

using ll = long long;
/**
 * Compute GCD(a, b)
 */
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (!a) {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

/**
 * Solve the Diophantine equation: a * x0 + b * y0 = c
 * 
 * g = gcd(a, b)
 * 
 * Particular solution: (x0, y0)
 * General solution: (x0 + k * b / g, y0 - k * a / g), for every k
 */
bool diophantine(ll a, ll b, ll c, ll& x0, ll& y0, ll& g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main() {
    ll x, y, g;
    diophantine(2, 7, 25, x, y, g);
    cout << x << ' ' << y << ' ' << g << '\n';
    return 0;
}