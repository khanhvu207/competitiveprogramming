#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	while (cin >> n) {
		if (!n) return 0;
		cout << (n < 3 ? "Alice\n" : "Bob\n");
	}
}