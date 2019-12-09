#include <iostream>

using namespace std;
#define N 1000000007
int main() {
	int n;
	cin >> n;
	int res = 0;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		res = (res + a % N) % N;
	}

	cout << res;

	return 0;
}
