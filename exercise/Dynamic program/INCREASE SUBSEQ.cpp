/*

*/

#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;
int arr[1000001];
int f[1000001];

void dayConTangDaiNhat(int n) {
  for (int i = 0; i < n; i++) {
    // find max
    int max = 0;
    for (int j = 1; j < i; j++) {
      if (arr[j] < arr[i]) {
        if (f[j] > max) {
          max = f[j];
        }
      }
    }
    f[i] = max + 1;
  }
}

int getResult(int n) {
  int res = f[0];
  for (int i = 1; i < n; i++) {
    if (res < f[i]) {
      res = f[i];
    }
  }
  return res;
}

int main() {
  // input
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  dayConTangDaiNhat(n);
  cout << getResult(n);

  return 0;
}
