#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1E9 + 7;
const int N = 2E5 + 5;
ll p[N];
vector<ll> pentagonal;

/**
 * Compute Partition function P(i) for every i upto MX
 * https://en.wikipedia.org/wiki/Partition_function_(number_theory)
 * Method: https://math.stackexchange.com/questions/607139/how-to-use-pentagonal-number-theorem-to-determine-partitions-of-n
 * 
 * Time complexity: O(MX ^ 1.5)
 * 
 * Example: P(4) = 5
 * 4 = 1 + 1 + 1 + 1
 *   = 1 + 1 + 2
 *   = 1 + 3
 *   = 2 + 2
 *   = 4
 * 
 * Results are taken modulo of MOD = 1E9 + 7
 * 
 * Execution time on:
 *      Codeforces: ~1326ms
 */
void compute_p_function (int MX){
	for (int i = 1; i < MX; ++i) 
	    pentagonal.push_back(i), pentagonal.push_back(-i);
	
	transform(pentagonal.begin(), pentagonal.end(), pentagonal.begin(), [](ll k){
	    return k * (3LL * k - 1LL) / 2LL;
	    
	});
	
	p[0] = 1; 
	p[1] = 1; 
	p[2] = 2;
	for (int i = 3; i < MX; ++i)
		for (int j = 0; j < (int)pentagonal.size() && pentagonal[j] <= i; ++j)
			if (j % 4 < 2) p[i] = (p[i] + p[i - pentagonal[j]] % MOD) % MOD;
			else p[i] = (p[i] - p[i - pentagonal[j]] % MOD + MOD) % MOD;
}

int main() {
    compute_p_function(N);
    return 0;
}