struct DSU
{
	vector<int> r, p;
	DSU(int n)
	{
		r.resize(n, 1);
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}

	int getRoot(int u)
	{
		return p[u] == u ? u : p[u] = getRoot(p[u]);
	}

	bool merge(int u, int v)
	{
		u = getRoot(u);
		v = getRoot(v);
		if (u == v) return false;
		if (r[u] > r[v]) r[u] += r[v], p[v] = u;
		else r[v] += r[u], p[u] = v;
		return true;
	}
};

