#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
const int K = 20;

int sz[N];
int ans[N];
int par[N];
int depth[N];
int anc[N][K];

bool vis[N];

vector <int> Tree[N];

void preCalc(int u, int p, int d) {
	depth[u] = d;
	anc[u][0] = p;
	for (int v : Tree[u]) if (v != p)
		preCalc(v, u, d + 1);
}

int getSize(int u, int p) {
	sz[u] = 1;
	for (int v : Tree[u])
		if (v != p && !vis[v])
			sz[u] += getSize(v, u);
	return sz[u];
}

int getCentroid(int u, int p, int compSz) {
	for (int v : Tree[u])
		if (v != p && !vis[v] && sz[v] > compSz / 2)
			return getCentroid(v, u, compSz);
	return u;
}

int solve(int u)
{
	getSize(u, 0);
	int c = getCentroid(u, 0, sz[u]);

	vis[c] = true;
	for (int v : Tree[c]) if (!vis[v]) {
		int child = solve(v);
		par[child] = c;
	}
	return c;
}

int LCA(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);

	for (int k = 17; k >= 0; --k)
		if (depth[u] - (1 << k) >= depth[v])
			u = anc[u][k];

	if (u == v) return u;

	for (int k = 17; k >= 0; --k)
		if (anc[u][k] != anc[v][k]) {
			u = anc[u][k];
			v = anc[v][k];
		}

	return anc[u][0];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2*depth[LCA(u, v)];
}

void update(int u) {
	int v = u;
	while (v) {
		ans[v] = min(ans[v], dist(u, v));
		v = par[v];
	}
}

int query(int u) {
	int res = ans[u], v = u;
	while (v) {
		res = min(res, ans[v] + dist(u, v));
		v = par[v];
	}
	return res;
}

int main()
{
	int n, m;	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v;	scanf("%d%d", &u, &v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
		ans[i] = ans[n] = 1e9;
	}

	preCalc(1, 0, 1);
	for (int k = 1; k <= 17; ++k)
		for (int u = 1; u <= n; ++u)
			anc[u][k] = anc[anc[u][k - 1]][k - 1];

	for (int i = 1; i <= n; i++)
		ans[i] = dist(1, i);

	solve(1);
	while (m--) {
		int t, v;	scanf("%d%d", &t, &v);

		if (t == 1)
			update(v);
		else
			printf("%d\n", query(v));
	}

	return 0;
}
