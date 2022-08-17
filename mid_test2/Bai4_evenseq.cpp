/*
5
-2 1 -4 4 9

5
9 3 4 7 9

ouput:
10
*/
#include <iostream>

using namespace std;

int arr[100001];
int NF = -1000000;
int f[100001];
int g[100001];

void dynamic(int n) {
  /*
  f[i] : max chan
  g[i] : max le
  */
  if (arr[1] % 2 == 0) {
    f[1] = arr[1];
    g[1] = -1000000;
  } else {
    g[1] = arr[1];
    f[1] = -1000000;
  }
  for (int i = 2; i <= n; i++) {
    if (arr[i] % 2 == 0) {
      if (f[i - 1] > NF) {
        f[i] = (f[i - 1] + arr[i] > arr[i]) ? f[i - 1] + arr[i] : arr[i];
      } else {
        f[i] = arr[i];
      }

      g[i] = (g[i - 1] > NF) ? g[i] = g[i - 1] + arr[i] : NF;
    } else {
      if (g[i - 1] > NF) {
        f[i] = g[i - 1] + arr[i];
      } else {
        f[i] = NF;
      }

      if (f[i - 1] > NF) {
        g[i] = (f[i - 1] + arr[i] > arr[i]) ? f[i - 1] + arr[i] : arr[i];
      } else {
        g[i] = arr[i];
      }
    }
    cout << f[i] << " " << g[i] << " "
         << "\n";
  }
  int res = f[1];
  for (int i = 2; i <= n; i++) {
    if (res < f[i]) {
      res = f[i];
    }
  }
  cout << res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    //    	arr[i] += arr[i-1];
  }
  //
  //	int res = -1000000;
  //	for(int i=0;i<=n;i++){
  //		for(int j=1;j<=n;j++){
  //			int sum = arr[j] - arr[i];
  //			if(sum % 2 ==0){
  //				if(res < sum){
  //					res = sum;
  //				}
  //			}
  //		}
  //	}
  //    cout<<res;
  dynamic(n);

  return 0;
}
