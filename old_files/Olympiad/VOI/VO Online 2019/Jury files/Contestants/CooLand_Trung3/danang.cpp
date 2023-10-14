#include<bits/stdc++.h>
#define int 				long long
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c) && c != '-');
	bool Minus = false; if (c == '-') { Minus = true; c = getchar(); }
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
	if (Minus) val = -val;
}

typedef pair<int, int> ii;
struct data {
	int u, v, w;
	data() {}; data(int u, int v, int w) : u(u), v(v), w(w) {};
	bool operator < (const data &a) const { return w < a.w; }
};	

const int N = 4e5 + 4, oo = 1e17 + 4;
int n, m, D;
vector<data> Edge;
vector<int> adj[N];

int d[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;

int Binary_Search(int v, int w) {
	int l = 0, r = adj[v].size()-1, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2, id = adj[v][mid];
		if (Edge[id].w >= w) { ans = mid; r = mid - 1; }
		else l = mid + 1;
	}
	return ans;
}

void Lazy_Dijkstra() {
	for (int i = 0; i < (int) Edge.size(); ++i) d[i] = oo;
	for (int id : adj[1]) {
		d[id] = Edge[id].w;
		pq.push(ii(d[id], id));
	}  

	int res = -1;
	while (pq.size()) {
		int id = pq.top().second, val = pq.top().first; pq.pop();
		if (d[id] != val) continue;
		int u = Edge[id].u, v = Edge[id].v;
		if (v == n) res = (res == -1) ? d[id] : min(res, d[id]);

		int pos = lower_bound(adj[u].begin(), adj[u].end(), id) - adj[u].begin();
		if (pos < (int) adj[u].size()-1) {
			int ore = adj[u][pos+1];
			if (d[ore] > d[id] - Edge[id].w + Edge[ore].w) {
				d[ore] = d[id] - Edge[id].w + Edge[ore].w;
				pq.push(ii(d[ore], ore));
			}
		}

		pos = Binary_Search(v, Edge[id].w+D);
		if (pos != -1) {
			int ore = adj[v][pos];
			if (d[ore] > d[id] + Edge[ore].w) {
				d[ore] = d[id] + Edge[ore].w;
				pq.push(ii(d[ore], ore));
			}
		} 
 	}
 	cout << res << '\n';
}

void sol() {
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < (int) Edge.size(); ++i) {
		int u = Edge[i].u;
		adj[u].push_back(i);
	}

	Lazy_Dijkstra();
}	

#undef int
int main() {
#define int 				long long
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}
	else if (fopen("danang.inp", "r")) {
		freopen("danang.inp", "r", stdin);
		freopen("danang.out", "w", stdout);
	}

	Read(n); Read(m); Read(D); 
	int u, v, w;
	for (int i = 1; i <= m; ++i) {
		Read(u); Read(v); Read(w);
		Edge.push_back(data(u, v, w));
		Edge.push_back(data(v, u, w));
	}

	sol();

	return 0;
}