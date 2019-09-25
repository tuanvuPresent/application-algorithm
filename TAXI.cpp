/*
There are nn passengers 1,2,…,n1,2,…,n. 
The passenger ii want to travel from point ii to point i+n(i=1,2,…,n)i+n(i=1,2,…,n). 
There is a taxi located at point 00 for transporting the passengers. 
Given the distance matrix c(2n+1)*(2n+1) in which c(i,j)c(i,j) 
is the traveling distance from point ii to point j(i,j=0,1,…,2n)j(i,j=0,1,…,2n) 
Compute the shortest route for the taxi, serving nn passengers and coming back to point 00 such that at any moment, 
there are no more than one passenger in the taxi, and no point is visited more than once (except for point 00).

Input
Line 11 contains n(1=n=11)n(1=n=11). Line i+1(i=1,2,…,2n+1)i+1(i=1,2,…,2n+1) contains the ithith line of the matrix cc.

Output
Unique line contains the length of the shortest route.
input:
2
0 8 5 1 10
5 0 9 3 5
6 6 0 8 2
2 6 3 0 7
2 5 3 4 0
output:
17
*/

#include <iostream>

using namespace std;

int matrix[25][25] = { 0 };
int visit[11] = { 0 };
int result = 999999999;

void DFS(int x, int n, int sum, int count)
{
    if (count == n) {
        result = min(result, sum + matrix[x][0]);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0 && sum + matrix[x][i] + matrix[i][i+n] < result) {
            visit[i] = 1;
            DFS(i + n, n, sum + matrix[x][i] + matrix[i][i+n], count + 1);
            visit[i] = 0;
        }
    }
}


int main()
{
    //input
    int n;
    cin >> n;
    for (int i = 0; i <= n + n; i++) {
        for (int j = 0; j <= n + n; j++) {
            cin >> matrix[i][j];
        }
    }
    //handle
	DFS(0, n, 0, 0);
    //show output
    cout << result;

    return 0;
}
