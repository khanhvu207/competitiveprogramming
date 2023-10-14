#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<int> mob;

/**
 * Compute the mobius function for every i up to MX
 * https://codeforces.com/blog/entry/53925
 * Time complexity: O(MX * log(MX))
 */
void mobius (const int MX) {
	mob.resize(MX + 1, 2);
	mob[1] = 1;
	for(ll i = 2; i <= MX; ++i) 
	    if (mob[i] == 2) {
    		if(i * i <= MX) 
    		    for (ll j = i * i; j <= MX; j += i*i) mob[j]=0;
    		for (ll j = i; j <= MX; j += i) {
    			if (mob[j] == 2) mob[j] = 1;
    			mob[j] = -mob[j];
    		}
	    }
}

int main() {
    mobius(1E6 + 5);
    return 0;
}