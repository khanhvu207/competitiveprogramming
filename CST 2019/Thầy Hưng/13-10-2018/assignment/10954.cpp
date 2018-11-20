#include <iostream>
#include <queue>
using namespace std;

#define datatype unsigned long long int

struct data {
	datatype v;
};

bool operator <(const data & a, const data & b) {
	return a.v > b.v;
}

int main() {
	freopen("10954.inp", "r", stdin);
	freopen("10954.out", "w", stdout);
	int n;
	cin >> n;
	while (n) {

		priority_queue<data> q;
		for (int i = 0; i < n; i++) {
			datatype v;
			cin >> v;
			q.push( { v });
		}

		datatype sol = 0;
		while (q.size() > 1) {
			datatype a = q.top().v;
			q.pop();
			datatype b = q.top().v;
			q.pop();
			datatype sum = a + b;
			sol += sum;
			q.push( { sum });
		}

		cout << sol << endl;
		cin >> n;
	}
	return 0;
}