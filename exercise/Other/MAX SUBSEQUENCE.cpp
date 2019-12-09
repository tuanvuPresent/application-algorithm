/*

*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int arr[1000001];

int main() {
	//input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//handle
	int sum = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (sum > 0) {
			sum += arr[i];
		} else {
			sum = arr[i];
		}
		res = max(sum, res);
	}

	//show output
	cout << res;

	return 0;
}
