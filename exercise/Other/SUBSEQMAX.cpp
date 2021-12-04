#include <iostream>

using namespace std;

int arr[1000000] = {0};

int main() {
  int n = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  //
  long long max = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    sum = (sum < 0) ? 0 : sum;

    max = (max < sum) ? sum : max;
  }
  cout << max << endl;

  return 0;
}
