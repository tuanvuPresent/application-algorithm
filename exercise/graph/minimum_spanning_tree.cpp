/*
inputCopy
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
outputCopy
7

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Graph {
  int x;
  int y;
  int v;
};
vector<Graph> g;
int fron[100001], cnt[100001];
bool cmp(Graph g1, Graph g2) { return g1.v < g2.v; }

int find(int u) {
  if (fron[u] != u)
    fron[u] = find(fron[u]);
  return fron[u];
}

bool join(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return false;

  if (cnt[u] == cnt[v])
    cnt[u]++;
  if (cnt[u] < cnt[v])
    fron[u] = v;
  else
    fron[v] = u;
  return true;
}

void kruskal() {
  long long res = 0;
  for (int i = 0; i < g.size(); i++) {
    if (join(g[i].x, g[i].y)) {
      res += g[i].v;
    }
  }
  // show output
  cout << res;
}

int main() {
  // input
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    Graph g1;
    cin >> g1.x >> g1.y >> g1.v;
    g.push_back(g1);
  }
  sort(g.begin(), g.end(), cmp);
  for (int i = 1; i <= n; i++) {
    fron[i] = i;
    cnt[i] = 0;
  }
  // solve
  kruskal();

  return 0;
}
