/*
Given a directed graph G=(V,A)G=(V,A) where V={1,�,n}V={1,�,n} is the set of
nodes. Each arc (u,v)?A(u,v)?A has weight w(u,v)w(u,v). Given s,t?Vs,t?V,
compute the shortest path from ss to tt.

Input
Line 1: nn and mm (1=n=105,1=m=1061=n=105,1=m=106)
Line i+1i+1 (i=1,�,mi=1,�,m): positive integers uu, vv, and ww in which ww is
the weight of arc (u,v)(u,v) Line m+2: ss, tt Output Write the weight of the
shortest path found or -1 if no path from ss to tt exists.

inputCopy
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5
outputCopy
97
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
  }
  int start, end;
  cin >> start >> end;
  // handle
  for (int i = 1; i <= n; i++)
    a[i].push_back(ii(0, 0));
  dijkstra(start, end);
  // show output
  cout << res;

  return 0;
}
