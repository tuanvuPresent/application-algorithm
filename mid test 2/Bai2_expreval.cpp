/*
input:
6
3 5 3 2 7 4
0 1 2 2 1
output:
44
*/
#include <algorithm>
#include <iostream>

long long arr[200001];
int phepTinh[200000];

using namespace std;

long long sum(int n) {
  long long res = arr[0];
  for (int i = 1; i < n; i++) {
    if (phepTinh[i] != 2) {
      if (i == n - 1 || phepTinh[i + 1] != 2)
        switch (phepTinh[i]) {
        case 0:
          res -= arr[i];
          break;
        case 1:
          res += arr[i];
          break;
        }
      else {
        int sum = arr[i];
        int j = i;
        while (i + 1 < n && phepTinh[i + 1] == 2) {
          sum *= arr[i + 1];
          i++;
          if (res < 0) {
            res += 1000000007;
          }
          sum %= 1000000007;
        }
        switch (phepTinh[j]) {
        case 0:
          res -= sum;
          break;
        case 1:
          res += sum;
          break;
        }
      }
    } else {
      res *= arr[i];
    }
    if (res < 0) {
      res += 1000000007;
    }
    res %= 1000000007;
  }
  return res;
}

int main() {
  // input
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 1; i < n; i++)
    cin >> phepTinh[i];
  //
  long long res = sum(n);
  // show output
  cout << res;

  return 0;
}
