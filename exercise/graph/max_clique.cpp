/*
inputCopy
5 8
1 2
1 3
2 3
2 4
2 5
3 4
3 5
4 5
outputCopy
4
*/
#include <algorithm>
#include <iostream>
int graph[16][16];
int res = 0;

using namespace std;

int check(int k, int start) {
  for (int i = start; i <= k + start - 1; i++) {
    for (int j = i + 1; j <= k + start - 1; j++) {
      if (!graph[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

int counting(int n) {
  for (int k = n; k >= 1; k--) {
    for (int start = 1; start <= n - k + 1; start++) {
      if (check(k, start)) {
        return k;
      }
    }
  }
}
int visit[16];
int x[16];
int checkAdd(int v, int n) {
  for (int i = 0; i < n; i++) {
    if (!graph[v][x[i]]) {
      return 0;
    }
  }
  return 1;
}

void dfs(int n, int k, int v) {
  res = max(res, k);
  for (int i = 1; i <= n; i++) {
    if (!visit[i] && checkAdd(i, k)) {
      x[k] = i;
      visit[i] = 1;
      dfs(n, k + 1, i);
      visit[i] = 0;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  // handle
  dfs(n, 0, 0);
  // show output
  cout << res;

  return 0;
}
