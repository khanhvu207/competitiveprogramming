/*input

*/
#include <bits/stdc++.h>
#include "testlib_themis.h"
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define bit(x, y) ((x >> y) & 1LL)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; i--)
// const int N=;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

#define M 10000005
int primes[M];
void eratosthene() {
	for (int i = 2; i <= M - 5; i++) if (primes[i] == 0) for (int j = i; j <= M - 5; j += i) primes[j] = i;
}

void modify(int cnt[], int num, int add, int stepID = -1, char A_or_B = '!') {
	while (num > 1) {
		int val = primes[num];
		while (primes[num] == val) {
			num /= val;
			cnt[val] += add;
		}
		if (cnt[val] < 0)
			quitf(_wa, "After step #%d: Exponent of number %c, prime %d became negative.", stepID, A_or_B, val);
	}
}
int cnt[2][M];
// cnt[0] la cua "Duc gay to"
// cnt[1] la cua "Thang de thuong"

int main(int argc, char *argv[]) {
#ifdef THEMIS
	registerTestlibThemis("vector.inp", "vector.out");
#else
	registerTestlibCmd(argc, argv);
#endif // THEMIS
	eratosthene();
	int n = inf.readInt(1, 300, "Size of array A");
	vector<int> A = inf.readInts(n, 1, 1e7, "Array A");
	for (auto it : A) modify(cnt[0], it, 1);
	int m = inf.readInt(1, 300, "Size of array B");
	vector<int> B = inf.readInts(m, 1, 1e7, "Array B");
	for (auto it : B) modify(cnt[1], it, 1);
	// check contestant answer
	int q; q = ouf.readInt(0, 1e6, "Number of steps"); 
	loop(Q, 1, q) {
		int P = ouf.readInt(1, 1e7, "Number P");
		string s = ouf.readWord("W|D|L", "Game result");
		if (s[0] == 'W') {
			modify(cnt[0], P, 1, Q, 'A'); // Thang de thuong  	them P lan
			modify(cnt[1], P, -2, Q, 'B'); // Duc gay to 		giam P^2 lan
		}
		else if (s[0] == 'L') {
			modify(cnt[0], P, -2, Q, 'A'); // Thang de thuong 	giam P^2 lan
		}
		else {
			modify(cnt[1], P, 1, Q, 'B'); // Duc gay to 		tang P lan
		}
	}
	loop(i, 2, M - 5) {
		if (cnt[0][i] != 0 || cnt[1][i] != 0)
			quitf(_wa, "Number %c is still divisible by %d at the end.", (cnt[0][i] != 0 ? 'A' : 'B'), i);
	}
	quitf(_ok, "Correct solution, contestant use %d steps", q);
}