#include <iostream>

using namespace std;

int arr[100001];
int f[100001];

void solve(int n, int a, int b)
{
	f[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = a; j <= b; j++)
		{
			int temp = 0;
			if (i - j >= 0)
			{
				temp = f[i - j];
			}
			f[i] = max(temp, f[i]);
		}
		f[i] += arr[i];
	}
	//
	int res = f[0];
	for (int i = 1; i < n; i++)
	{
		if (res < f[i])
		{
			res = f[i];
		}
	}
	cout << res;
}

int main()
{ 
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve(n, a, b);

	return 0;
}
