#include <iostream>

using namespace std;

int coin[] = {1, 5, 10, 50, 100, 500};
int f[1001];

void creat(int n) {
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 999999999;
		for (int j = 0; j < 6; j++) {
			if (i - coin[j] >= 0) {
				f[i] = min(f[i - coin[j]], f[i]) + 1;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	creat(1000);
	cout << f[1000 - n];

	return 0;
}
