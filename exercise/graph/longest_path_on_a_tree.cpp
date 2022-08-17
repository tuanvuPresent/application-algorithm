/*
inputCopy
6
1 3 3
1 6 2
2 6 5
4 5 2
4 6 1
outputCopy
10

*/
#include <algorithm>
#include <iostream>
#define MAX 100001
#include <string.h>
#include <vector>

using namespace std;

vector<int> A[100001];
vector<int> d[100001];
int visited[100001];
int res = 0;
// int X[100001];
int u = 1;

int check(int x) {
  for (int i = 0; i < A[x].size(); i++) {
    if (!visited[A[x][i]])
      return 0;
  }
  return 1;
}

void dfs(int x, int k, int n, int sum) {
  if (check(x)) {
    if (res < sum) {
      res = sum;
      u = x;
    }
    //		for(int i=0;i<n-1;i++) cout<<X[i]<<" ";
    //		cout<<"\n";
    return;
  }

  for (int i = 0; i < A[x].size(); i++) {
    if (!visited[A[x][i]]) {
      visited[A[x][i]] = 1;
      //			X[k] = A[x][i];
      dfs(A[x][i], k + 1, n, sum + d[x][i]);
      visited[A[x][i]] = 0;
    }
  }
}

int main() {
  // input
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, v;
    cin >> a >> b >> v;
    A[a].push_back(b);
    A[b].push_back(a);
    d[a].push_back(v);
    d[b].push_back(v);
  }
  // solve
  //	X[0] = 1;
  visited[1] = 1;
  dfs(1, 1, n, 0);
  memset(visited, 0, sizeof(visited));
  dfs(u, 1, n, 0);
  // show output
  cout << res;

  return 0;
}
