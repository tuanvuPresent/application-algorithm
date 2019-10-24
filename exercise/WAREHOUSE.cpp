#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int time[1001];
int f[101][1001];

void solve(int n, int t, int d)
{
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int p = i - time[j];
			if (p >= 0)
			{
				//find max at row p
				int max = 0;
				for (int k = 1; k <= d; k++)
				{
					if (j - k > 0 && max < f[p][j - k])
						max = f[p][j - k];
				}
				f[i][j] = max + a[j];
			}
			else
			{
				f[i][j] = 0;
			}
			//			cout<<f[i][j]<<" ";
		}
		//		cout<<"\n";
	}

	//find max
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < f[t][i])
		{
			max = f[t][i];
		}
	}
	cout << max;
}

int main()
{
	//input
	int n, t, d;
	cin >> n >> t >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> time[i];

	//handle
	solve(n, t, d);

	return 0;
}
