/*
input:
4 10
0 1 2 6
1 0 5 4
2 5 0 3
6 4 3 0
output:
2
*/

#include <iostream>
#include <string.h>

using namespace std;

int matrix[20][20] = {0};
int visit[20] = {0};
int result = 0;
int smin = 999999999;
int M;

void DFS(int x, int n, int sum, int count) {
  if (count == n - 1) {
    if (sum + matrix[x][0] <= M)
      result++;
    return;
  }
  for (int i = 1; i < n; i++) {
    if (visit[i] == 0 && matrix[x][i] + sum + smin * (n - count - 1) <= M) {
      visit[i] = 1;
      DFS(i, n, sum + matrix[x][i], count + 1);
      visit[i] = 0;
    }
  }
}

int main() {
  // input
  int n;
  cin >> n;
  cin >> M;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
      if (i != j) {
        smin = min(smin, matrix[i][j]);
      }
    }
  }
  // handle
  DFS(0, n, 0, 0);
  // show output
  cout << result;

  return 0;
}
