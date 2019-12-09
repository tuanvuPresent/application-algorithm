/*
input
5 7 3
1 2 4
1 3 3
1 4 1
2 3 2
2 5 6
3 4 5
3 5 5

output
6

*/

#include<iostream>
#include <algorithm>
#include <vector>

int graph[32][32];

using namespace std;
int res = 1e9;

struct Graph {
	int x;
	int y;
	int v;
};
vector <Graph> g;
int root[32], cnt[32];
int visit[100001];

int find(int u) {
	if (root[u] != u) root[u] = find(root[u]);
	return root[u];
}

bool join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;

	if (cnt[u] == cnt[v]) cnt[u]++;
	if (cnt[u] < cnt[v])
		root[u] = v;
	else
		root[v]=u;
	return true;
}

void isConnect(int k, int n, int x) {
	visit[x] = 1;
	if(k == n) {
		return;
	}
	for(int i=0; i<g.size(); i++) {
		if(visit[v[x][i]] == 0) {
			isConnect(k+1, n,v[x][i]);
		}
	}
}

void DFS(int k, int n, int sum) {
	if(k == n) {
		if(res > sum && isConnect(k, x)) {
			res = sum;
		}
		return;
	}
	for(int i=0; i < g.size(); i++) {
		int x1 = g[i].x;
		int y1 = g[i].y;
		int ranku = cnt[x1];
		int rankv = cnt[y1];
		int rootu = root[x1];
		int rootv = root[y1];
		if(join(g[i].x, g[i].y)) {
			DFS(k+1, n, sum + g[i].v);
		}
		root[x1] = rootu;
		root[y1] = rootv;
		cnt[x1] = ranku;
		cnt[y1] = rankv;
	}
}

int main() {
	//input
	int v, n, k;
	cin>>v>>n>>k;
	for(int i=0; i<n; i++) {
		Graph g1;
		cin>>g1.x>>g1.y>>g1.v;
		g.push_back(g1);
	}
	//handle
	for (int i=1; i<=n; i++) {
		root[i] = i;
		cnt[i] = 0;
	}
	DFS(0,k,0);
	//show output
	cout<<res;

	return 0;
}

