#include <iostream>
using namespace std;

int arr[10001];

void init(int m) {
  for (int i = 1; i <= m; i++)
    arr[i] = i;
}

void show(int m) {
  for (int i = 1; i <= m; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

int toHop(int n, int m) {
  int i = m;
  while (i > 0 && arr[i] == n + i - m)
    i--;
  if (i > 0) {
    arr[i]++;
    for (int j = i + 1; j <= m; j++)
      arr[j] = arr[j - 1] + 1;
    return 1;
  } else {
    return 0;
  }
}

int check(int n, int m, int k) {
  // c[m,n] >= k
  if (m > n / 2)
    m = n - m;
  double a = 1;
  for (int i = 2; i <= m; i++) {
    a *= (1 / (double)i);
  }
  for (int i = 0; i < m; i++) {
    a *= (double)(n - i);
    if (a >= k) {
      return 1;
    }
  }
  return (a >= k);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  init(m);

  if (check(n, m, k)) {
    k--;
    while (k--) {
      toHop(n, m);
    }
    show(m);
  } else {
    cout << "-1";
  }

  return 0;
}
