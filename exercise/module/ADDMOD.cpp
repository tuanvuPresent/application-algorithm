#include <iostream>

using namespace std;

int N = 1000000007;
int main()
{
    int a, b;
    cin >> a >> b;
    int res = (a % N + b % N) % N;
    cout << res;

    return 0;
}
