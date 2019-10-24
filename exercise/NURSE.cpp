/*
inputCopy
6 2 3
outputCopy
4
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
int res = 0;

void solve(int n, int k1, int k2)
{
	/*
	 	12 45 78
	 	123 56
	 	123 567
	 	23 56
	 	23 567
	 	234 67
	 	234 678
	 	34 67
	 	34 678
	 	345 78
	 	45 78
	*/
	for (int k = 0; k <= n - k1 - k1 - 1; k++)
	{
		for (int i = k1; i <= k2; i++)
		{
			int x = n - i - 1 - k;
			if (x >= k2)
			{
				res += k2 - k1 + 1;
			}
			else if (x >= k1)
			{
				res += x - k1 + 1;
			}
			int mul = (n / (k + i + 1 + k2));
			if (mul)
				res *= mul;
			res %= mod;
			cout << mul << " ";
		}
	}
}

int main()
{
	//input
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	solve(n, k1, k2);
	cout << res;

	return 0;
}
