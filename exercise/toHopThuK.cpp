#include <iostream>
using namespace std;

int arr[10001];

void init(int m)
{
	for (int i = 1; i <= m; i++)
		arr[i] = i;
}

void show(int m)
{
	for (int i = 1; i <= m; i++)
		cout << arr[i];
	cout << "\n";
}

int toHop(int n, int m)
{
	int i = m;
	while (i > 0 && arr[i] == n + i - m)
		i--;
	if (i > 0)
	{
		arr[i]++;
		for (int j = i + 1; j <= m; j++)
			arr[j] = arr[j - 1] + 1;
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int m = 3;
	init(m);
	while (toHop(6, m))
		show(m);

	return 0;
}
