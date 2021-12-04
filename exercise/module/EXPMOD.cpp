#include <iostream>

using namespace std;

#define N 1000000007

long long solve(int a, int b) {
  long long res = a;
  for (int i = 1; i < b; i++) {
    res = (res * a % N) % N;
  }
  return res;
}

long long solve2(long long a, long long b) {
  long long res;
  if (b == 1)
    return a % N;
  if (b % 2 == 0) {
    res = solve2(a, b / 2);
    res = (res * res) % N;
  } else {
    res = solve2(a, b / 2);
    res = (((res * res) % N) * a) % N;
  }

  return res;
}

int main() {
  // input
  long long a, b;
  cin >> a >> b;
  // handle
  long long res = solve2(a, b);
  // output
  cout << res;

  return 0;
}
