#include <algorithm>
#include <iostream>

using namespace std;

int arr[100001];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);

  // handle
  int res = 1;
  int j = 1;
  for (int i = n - 1; i >= 0; i--) {
    int temp = arr[i] + j;
    j++;
    if (res < temp) {
      res = temp;
    }
  }
  // show output
  cout << (res + 1);

  return 0;
}
