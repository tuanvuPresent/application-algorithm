/*
inputCopy
5 7 3
1 2 4
1 3 3
1 4 1
2 3 2
2 5 6
3 4 5
3 5 5
outputCopy
6
*/

#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
int graph1[51][51];
int res = 25000;
int temp[51];

int check(int v, int k) {
  for (int i = 0; i < k; i++) {
    if (graph1[v][temp[i]] != 0) {
      return 1;
    }
  }
  return 0;
}

void DFS(int k, int cnt, int v, int sum, int n) {
  if (k + 1 == cnt) {
    if (res > sum) {
      res = sum;
    }
    return;
  }
  for (int i = v + 1; i <= n; i++) {
    if (v == 0 || check(i, cnt)) {
      temp[cnt] = i;

      int m = (v == 0) ? 0 : 100;
      for (int j = 0; j <= cnt; j++) {
        if (graph1[i][temp[j]] && m > graph1[i][temp[j]]) {
          m = graph1[i][temp[j]];
        }
      }
      DFS(k, cnt + 1, i, sum + m, n);
    }
  }
}

int main() {
  // input
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y, w1;
    cin >> x >> y >> w1;
    graph1[x][y] = w1;
    graph1[y][x] = w1;
  }
  // solve
  DFS(k, 0, 0, 0, n);
  // show output
  if (res == 25000) {
    cout << -1;
  } else {
    cout << res;
  }

  return 0;
}
