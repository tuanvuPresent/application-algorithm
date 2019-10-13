/*

*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int x[1000001];
int y[1000001];

int temp[1000001] = {0};
int f[1000001] = {0};

void dayConChungDaiNhat(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (x[i] == y[j])
			{
				f[j] = temp[j - 1] + 1;
			}
			else
			{
				f[j] = max(temp[j], f[j - 1]);
			}
		}
		//copy array
		for (int k = 1; k <= m; k++)
			temp[k] = f[k];
	}
}

int getResult(int n, int m)
{
	return f[m];
}

int main()
{
	//input
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= m; i++)
		cin >> y[i];

	dayConChungDaiNhat(n, m);
	cout << getResult(n, m);

	return 0;
}
