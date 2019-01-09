#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define f first
#define s second
#define mk make_pair

const int N = 1e5 + 5;
int n, m;
int a[N], b[N];

int main() {

    #define file "VECTOR"
    freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> m;
    for(int i = 1; i <= m; ++ i) cin >> a[i];
    cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> b[i];

	cout << m * 4 + n * 6 << "\n";

	for(int i = 1; i <= m; ++ i) {
		cout << a[i] << " D\n";
		cout << a[i] << " D\n";
		cout << a[i] << " W\n";
		cout << a[i] << " L\n";
	}

	for(int i = 1; i <= n; ++ i) {
		cout << b[i] << " D\n";
		cout << b[i] << " D\n";
		cout << b[i] << " D\n";
		cout << b[i] << " W\n";
		cout << b[i] << " W\n";
		cout << b[i] << " L\n";
	}
    return 0;
}
