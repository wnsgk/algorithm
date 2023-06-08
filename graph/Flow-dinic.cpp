//V^2E
#include <bits/stdc++.h>

using namespace std;

const int MAX = 220;

int n, m;
int f[MAX][MAX], c[MAX][MAX], level[MAX], work[MAX];

vector<int> gph[MAX];

void make_edge(int u, int v, int x) {
	gph[u].push_back(v);
	gph[v].push_back(u);
	c[u][v] = x;
}

bool bfs(int s, int t) {
	memset(level, -1, sizeof level);
	queue<int> q;
	q.push(s);
	level[s] = 1;
	while(!q.empty()) {
		int u = q.front(); 
		q.pop();
		for(int v : gph[u]) {
			if(level[v] == -1 && c[u][v] - f[u][v] > 0) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return level[t] != -1;
}

int dfs(int now, int flow, int t) {
	if(now == t) return flow;
	for(int& i = work[now]; i < (int)gph[now].size(); ++i) {
		int v = gph[now][i];
		if(level[v] == level[now] + 1 && c[now][v] - f[now][v] > 0) {
			int ret = dfs(v, min(c[now][v] - f[now][v], flow), t);
			if(ret > 0) {
				f[now][v] += ret;
				f[v][now] -= ret;
				return ret;
			}
		}
	}
	return 0;
}

int dinic(int s, int t) {
	int ret = 0;
	while(bfs(s, t)) {
		memset(work, 0, sizeof work);
		while(true) {
			int flow = dfs(s, 1e9, t);
			if(flow == 0) break;
			ret += flow;
		}
	}
	return ret;
}

int main() {
    int a, b, x;
	cin>>n>>m;
	memset(c, 0, sizeof c);
	for(int i = 1; i <= n; ++i) {
		cin>>a;
		make_edge(0, i, a);
	}
	for(int i = 1; i <= m; ++i) {
		cin>>b;
		make_edge(i + 100, 210, b);
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin>>x;
			if(x == 0) continue;
			make_edge(j, i + 100, x);
		}
	}
	cout<<dinic(0, 210);
	return 0;
}
