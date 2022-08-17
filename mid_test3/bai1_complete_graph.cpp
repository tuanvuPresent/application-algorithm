/*
4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
output:
1
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int graph[1001][1001];
int check(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] == 0 && i != j) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  // input
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> graph[i][j];
    }
  }
  // handle
  cout << check(n);

  return 0;
}
