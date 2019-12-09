#include <bits/stdc++.h>

using namespace std;

const int N = 1<<20;

int s[N], t[N], ls[N], lt[N];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
		lt[t[i]] = max(lt[t[i]], t[i]-s[i]);
		ls[s[i]] = max(ls[s[i]], t[i]-s[i]);
	}

	for (int i = 1; i <= (int) 1e6; i++) {
		lt[i] = max(lt[i], lt[i-1]);
	}

	for (int i = (int) 1e6; i >= 1; i--) {
		ls[i] = max(ls[i], ls[i+1]);
	}

	int res = 0;

	for (int i = 1; i <= (int) 1e6; i++) {
		res = max(res, lt[i-1] + ls[i]);
	}

	cout << res << endl;

	return 0;
}
