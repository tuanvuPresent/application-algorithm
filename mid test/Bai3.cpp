/*
input:
5 5
2 3 4 1 5
output:
7
*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int arr[100001];

int solve(int n, int m) {
	int res = 0;
	int pos = 0;
	int run = 0;
	for (int i = 0; i < n; i++) {
		run -= (i > 0) ? arr[i - 1] : 0;
		while (pos < n && run + arr[pos] <= m) {
			run += arr[pos];
			pos++;
			res++;
		}
		res += (pos - i - 1);
	}
	return res;
}

int main() {
	//input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//handle
	int res = solve(n, m);
	//output
	cout << res;

	return 0;
}
