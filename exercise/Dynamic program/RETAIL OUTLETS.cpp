/*
input:
2 20
3 2
output:
3
*/

#include <iostream>
#include <algorithm>

using namespace std;

int mod = 1000000007;
int arr[501];
int f[50001][501];

void solve(int n, int M)
{
	//f[n,M] = f[n-1,M-a[n]] + f[n-1 , M-2a[n]]  +  ...
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = 1;
		for (int j = 1; j <= M; j++)
		{
			int x = (j - arr[i] >= 0) ? f[i][j - arr[i]] : 0;
			f[i][j] = (x + f[i - 1][j]) % mod;
			//			cout<<f[i][j]<<" ";
		}
		//		cout<<"\n";
	}
}

int main()
{
	//input
	int n, M;
	cin >> n >> M;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		M -= arr[i];
	}
	//handle
	solve(n, M);
	//show output
	cout << f[n][M];

	return 0;
}
