/*
6 10
1 2 2
1 5 6
1 6 1
2 3 8
2 6 4
3 4 7
3 6 2
4 5 3
4 6 5
5 6 4
3
1 3 4
*/

#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

const int oo = 1000000000;
typedef pair<int, int> ii;
vector<ii> a[100001];

int n;
int d[100001];
int res;
int result = 0;

void dijkstra(int start, int end) {
  priority_queue<ii, vector<ii>, greater<ii>> pq;

  for (int i = 1; i <= n; i++)
    d[i] = oo;
  d[start] = 0;
  pq.push(ii(0, start));

  while (pq.size()) {
    int u, du;
    u = pq.top().second;
    du = pq.top().first;
    pq.pop();
    if (du != d[u])
      continue;

    int v, uv;
    for (int i = 0; v = a[u][i].second; i++) {
      uv = a[u][i].first;
      if (d[v] > du + uv) {
        d[v] = du + uv;
        pq.push(ii(d[v], v));
      }
    }
  }

  res = d[end];
}

int main() {
  // input
  int m;
  cin >> n >> m;
  while (m--) {
    int p, q, w;
    cin >> p >> q >> w;
    a[p].push_back(ii(w, q));
    a[q].push_back(ii(w, p));
  }
  int k;
  cin >> k;
  int arr[101];
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }
  // handle
  for (int i = 1; i <= n; i++)
    a[i].push_back(ii(0, 0));
  for (int i = 0; i < k; i++) {
    dijkstra(arr[i], n);
    for (int j = 0; j < k; j++) {
      if (result < d[arr[j]]) {
        result = d[arr[j]];
      }
    }
    a[arr[i]].clear();
  }
  // show output
  cout << result;

  return 0;
}
