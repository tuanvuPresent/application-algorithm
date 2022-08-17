#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;

const int N = 100005;
const int oo = 0x3c3c3c3c;

int n, m, nums[N], lows[N], cnt = 0;
vector<int> a[N];
stack<int> st;
int ncount = 0;

void visit(int u) {
  lows[u] = nums[u] = ++cnt;
  st.push(u);

  for (int i = 0; int v = a[u][i]; i++)
    if (nums[v])
      lows[u] = min(lows[u], nums[v]);
    else {
      visit(v);
      lows[u] = min(lows[u], lows[v]);
    }

  if (nums[u] == lows[u]) { // found one
    ncount++;
    int v;
    do {
      v = st.top();
      st.pop();
      nums[v] = lows[v] = oo; // remove v from graph
    } while (v != u);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
  }
  for (int i = 1; i <= n; i++)
    a[i].push_back(0);

  for (int i = 1; i <= n; i++)
    if (!nums[i])
      visit(i);

  cout << ncount << endl;
}
