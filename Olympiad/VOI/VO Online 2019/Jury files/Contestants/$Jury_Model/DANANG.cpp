#include <iostream> 
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define For(i , a , b) for (int i = a , _b = b ; i <= _b ; ++i)
#define Ford(i , a  ,b) for (int i = a , _b = b : i >= _b ; --i)
#define Rep(i , n) for (int i = 0 , _n = n ; i < _n ; ++i)
#define sz(A) ((int)A.size())
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)


typedef pair<int , int> pt;

const int maxn = 400000 + 123;
int n, m;
int source, destination;
long long D;

struct edge {
	int u, v;
	long long w;

	void read() {
		cin >> u >> v >> w;
	}

	int other(int x) {
		return u ^ v ^ x;
	}

	bool operator < (const edge b) const {
		return w < b.w;
	}
} e[maxn];

struct state{
	int id;//id of this edge
	int u; 

	state() {
	}

	state(int _id, int _u) {
		id = _id;
		u = _u;
	}

	int encode() {
		///encode this state for dijkstra purpose
		if (e[id].u == (*this).u) return id * 2;
		return id * 2 + 1;
		///state will be counted from 2 to (2m + 1)
	}
};

std::vector<pair<int, long long> > V[maxn]; ///edge of new graph

std::vector<int> in[maxn], out[maxn];
bool cmpId(const int a, const int b) {
	return e[a] < e[b];
}

void buildNewGraph() {
	for (int id = 1; id <= m; id++) {
		int tmp[2] = {e[id].u, e[id].v};
		for (int dir = 0; dir < 2; ++dir) {
			int u = tmp[dir];
			///we are currently at state (id,u)
			int v = e[id].other(u);
			e[0].w = e[id].w + D; ///dummy for Bs
			int nxt = lower_bound(out[v].begin(), out[v].end(), 0, cmpId) - out[v].begin();

			if (nxt >= 0 && nxt < (int) out[v].size()) {
				nxt = out[v][nxt];
				int newU = state(id, v).encode();
				int newV = state(nxt, e[nxt].other(v)).encode();
				long long newW = e[nxt].w;
				V[newU].push_back(make_pair(newV, newW));
			}
		}
	}
	for (int v = 1; v <= n; v++) {
		///add edge between two consecutive edges
		for (int i = 0; i < (int)out[v].size() - 1; i++) {
			int p = out[v][i], q = out[v][i + 1];
			int newU = state(p, e[p].other(v)).encode();
			int newV = state(q, e[q].other(v)).encode();
			long long newW = e[q].w - e[p].w;
			V[newU].push_back(make_pair(newV, newW)); 
		}
	}
}

priority_queue<pair<long long, int> > qu;
long long d[maxn * 3];
const long long INF = (long long)1e18;

void dijkstra() {
	for (int i = 2; i <= 2 * m + 1; i++) d[i] = INF;
	while ((int)qu.size() > 0) qu.pop();
	for (int i = 1; i <= m; i++) {
		if (e[i].u == source) {
			int thisver = state(i, e[i].v).encode();
			d[thisver] = e[i].w;
			qu.push(make_pair(-d[thisver], thisver));
		}
		if (e[i].v == source) {
			int thisver = state(i, e[i].u).encode();
			d[thisver] = e[i].w;
			qu.push(make_pair(-d[thisver], thisver));
		}
	} 

	while ((int)qu.size() > 0) {
		pair<long long, int> cur = qu.top(); qu.pop();
		int u = cur.second;
		if (d[u] != -cur.first) continue;
		for (int i = 0; i < (int) V[u].size(); i++) {
			int v = V[u][i].first; long long w = V[u][i].second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				qu.push(make_pair(-d[v], v));
			}
		}
	}

	long long result = INF;
	for (int i = 1; i <= m; i++) {
		if (e[i].u == destination) {
			int thisver = state(i, e[i].u).encode();
			result = min(result, d[thisver]);
		}
		if (e[i].v == destination) {
			int thisver = state(i, e[i].v).encode();
			result = min(result, d[thisver]);
		}
	}

	if (result == INF) result = -1;
	cout << result << endl;
}

void ReadData() {
	cin >> n >> m >> D;
	source = 1, destination = n;
	for (int i = 1; i <= m; i++) e[i].read();
	for (int i = 1; i <= m; i++) {
		///this edge goes into u and out of v
		out[e[i].u].push_back(i);
		out[e[i].v].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		sort(out[i].begin(), out[i].end(), cmpId);
	}
}

void Process() {
	buildNewGraph();
	dijkstra();
}

int main() {
#ifdef THEMIS
	freopen("DANANG.INP", "r", stdin);
	freopen("DANANG.OUT", "w", stdout);
#endif // THEMIS

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("shortest.inp", "r", stdin);
	ReadData();
	Process();
	

	return 0;

}			