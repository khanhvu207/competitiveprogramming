#include <bits/stdc++.h>
using namespace std;

const int MX = 2E7 + 5;
int p[MX], g[MX];

/**
 * Sieve of Eratosthenes with Counting distinct prime divisors
 * Time complexity: O(n * log(log(n)))
 * Memory complexity: O(MX)
 * 
 * p[i] = smallest prime that divides i (if i is prime, p[i] = i)
 * g[i] = number of distinct prime divisors (for instance, g[6] = 2)
 * 
 * Execution time on:
 *      Codeforces: ~467ms
 */
void sieve() {
    iota(p, p + MX, 0);
	for (int i = 2; i * i < MX; ++i) 
		if (p[i] == i)
			for (int j = i * i; j < MX; j += i) 
				p[j] = p[j] == -1 ? i : min(p[j], i);
	g[1] = 0;
	for (int i = 2; i < MX; ++i) {
		g[i] = g[i / p[i]];
		if (p[i] != p[i / p[i]]) g[i] += 1;
	}
}

int main() {
    sieve();
    return 0;
}