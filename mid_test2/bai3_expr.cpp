/*
input:
6 12
3 2 7 5 2 3
output:
3
*/
#include <algorithm>
#include <iostream>

using namespace std;

int arr[32];
long long output[32][10000];
int res = 0;
int smin = 200;

void dynamic(int n) {
  // output(i,j) = output(i-1,j-arr[i]) + output(i-1,j+arr[i])
  output[1][arr[1] + 3000] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = -20; j <= 30; j++) {
      long long x =
          (j - arr[i] + 3000 >= 0) ? output[i - 1][j - arr[i] + 3000] : 0;
      long long y =
          (j + arr[i] + 3000 >= 0) ? output[i - 1][j + arr[i] + 3000] : 0;
      output[i][j + 3000] = (x + y + 1000000007) % 1000000007;
      //			cout<<x+y<<"";
    }
    //		cout<<"\n";
  }
}
void backtrack(int k, int n, int sum, int s) {
  if (k == n) {
    if (sum == s) {
      res++;
    }
    res %= 1000000007;
    return;
  }
  backtrack(k + 1, n, sum + arr[k + 1], s);
  backtrack(k + 1, n, sum - arr[k + 1], s);
}

int main() {
  // input
  int n, s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (smin > arr[i]) {
      smin = arr[i];
    }
  }
  // handle
  dynamic(n);
  //	backtrack(1,n,arr[1],s);
  // show output
  cout << output[n][s + 3000];
  //	cout<<res;

  return 0;
}
