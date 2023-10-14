#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;
const int N = 200;

int tc;
string line;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> tc;
	while (tc--) {
		double sx, sy;
		cin >> sx >> sy;
		getline(cin, line);
		double path = 0.0;
		while (true) {
			if (!getline(cin, line)) break;
			if (line == "") break;
			stringstream buffer(line);
			double ax, ay, bx, by;
			buffer >> ax >> ay >> bx >> by;
			path += pow(pow(ax - bx, 2.0) + pow(ay - by, 2.0), 0.5) / 1000.0 / 20.0 * 2.0;
		}
		int hours = path;
		int minutes = round((double)(path - hours) * 60.0);
		if (minutes == 60) {
			++hours;
			minutes = 0;
		}
		cout << hours << ':';
		if (minutes < 10)
			cout << '0';
		cout << minutes << '\n';
		if (tc) cout << '\n';
	}
}