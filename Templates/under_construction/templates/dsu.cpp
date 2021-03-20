#include <bits/stdc++.h>
using namespace std;

/**
 * Disjoint set union
 */
struct DSU{
	vector<int> r, p;
	DSU() {}
	
	/**
     * DSU constructor
     * @param n Expected number of elements
     */
	DSU(int n){
		r.resize(n, 1);
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}
	
	/**
     * Get the root of the element u
     * Optimization: Path compression
     * Time complexity: O(log(path from root -> u))
     * 
     * @return Root of u
     */
	int getroot(int u){
		return p[u] ==u ? u : p[u] = getroot(p[u]);
	}
	
	/**
     * Merge two element u and v
     * 
     * @return True if u and v were in different unions, False otherwise
     */
	bool merge(int u,int v){
		u = getroot(u);
		v = getroot(v);
		if (u == v) return false;
		if (r[u] > r[v]) r[u] += r[v], p[v] = u;
		else r[v] += r[u], p[u] = v;
		return true;
	}
};

int main() {
    DSU dsu = DSU();
    return 0;
}