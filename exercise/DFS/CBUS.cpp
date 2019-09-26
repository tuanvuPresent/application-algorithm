/*
There are nn passengers 1,2,…,n1,2,…,n. 
The passenger ii want to travel from point ii to point i+n(i=1,2,…,n)i+n(i=1,2,…,n). 
There is a bus located at point 00 and has kk places for transporting the passengers 
(it means at any time, there are at most k passengers on the bus). 
You are given the distance matrix c in which c(i,j)c(i,j) 
is the traveling distance from point ii to point j(i,j=0,1,…,2n)j(i,j=0,1,…,2n). 
Compute the shortest route for the bus, serving nn passengers and coming back to point 0
without visiting any point more than once (except for the point 00).

Input
Line 11 contains nn and k(1=n=11,1=k=10)k(1=n=11,1=k=10). 
Line i+1(i=1,2,…,2n+1)i+1(i=1,2,…,2n+1) contains the (i-1)th(i-1)th 
line of the matrix cc (rows and columns are indexed from 0,1,2,..,2n0,1,2,..,2n).

Output
Unique line contains the length of the shortest route.

Input
Line 11 contains n(1=n=11)n(1=n=11). Line i+1(i=1,2,…,2n+1)i+1(i=1,2,…,2n+1) contains the ithith line of the matrix cc.

Output
Unique line contains the length of the shortest route.
input:
3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
output:
25
*/

#include <iostream>

using namespace std;

int matrix[25][25] = { 0 };
int visit[25] = { 0 };
int result = 999999999;
int smin = 999999999;
int n, k;
int xx[25];

int check(int i, int soKhachTrenXe, int count){
	return 1;
}

void DFS(int x, int sum, int soKhachTrenXe, int count)
{
    if (count == n + n) {
        result = min(result, sum + matrix[x][0]);
        for(int i=0;i<6;i++) cout<<xx[i]<<" ";
        cout<<sum + matrix[x][0]<<"\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0 && soKhachTrenXe < k && sum  + matrix[x][i]  + ( 2 * n - count ) * smin < result) {
            visit[i] = 1;
            visit[i + n] = 1;
            xx[count] = i;
            DFS(i, sum + matrix[x][i], soKhachTrenXe + 1, count + 1);
            visit[i] = 0;
            visit[i + n] = 0;
        }
    }
    //neu co khack tren xe
    for (int i = 1; i <= n; i++) {
        if (visit[i + n] == 1 && sum + matrix[x][i+n] + ( 2 * n - count ) * smin < result) {
            visit[i + n] = 0;
            xx[count] = i+n;
            DFS(i + n, sum + matrix[x][i + n], soKhachTrenXe - 1, count + 1);
            visit[i + n] = 1;
        }
    }
}

int main()
{
    //input
    cin >> n >> k;
    for (int i = 0; i <= n + n; i++) {
        for (int j = 0; j <= n + n; j++) {
            cin >> matrix[i][j];
            if (i!=0 && j!=0 && i != j) {
                smin = min(smin, matrix[i][j]);
            }
        }
    }
    //handle
    DFS(0, 0, 0, 0);
    //show output
    cout << result;

    return 0;
}
