#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 2e5 + 5;
int64_t st[MAXN][20];

void prepare_table(int sz, int64_t *arr) {
	for (int i = 0; i < sz; ++i)
		st[i][0] = arr[i];
	
	for (int j = 1; j < 20; ++j)
		for (int i = 0; i + (1 << j) <= sz; ++i)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int64_t query(int l, int r) {
	int j = log2(r - l + 1);
	return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
