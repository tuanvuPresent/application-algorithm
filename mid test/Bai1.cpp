/*

*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int mod = 1000000007;
int arr[1000001];

long long solve(int n) {
	long long res = 1;
	for (int i = 0; i < n; i++) {
		res = (res * arr[i]) % mod;
	}

	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long res = solve(n);
	cout << res;

	return 0;
}
