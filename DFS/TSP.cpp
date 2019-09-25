/*
A person departs from point 0. He want to visit points 1,2,…,n,
once and come back to 0. Given c(i,j)which is the traveling distance 
from point i to point j(i,j=0,1,…,n), help that person to compute the shortest route.

Input
Line 1 contains n(1<=n<=15) Line i+1(i=1,2,…,n+1) contains the ithith line of the matrix c
Output
Unique line contains the length of the shortest route
input:
9
000 374 200 223 108 178 252 285 240 356
374 000 255 166 433 199 135 095 136 017
200 255 000 128 277 128 180 160 131 247
223 166 128 000 430 047 052 084 040 155
108 433 277 430 000 453 478 344 389 423
178 199 128 047 453 000 091 110 064 181
252 135 180 052 478 091 000 114 083 117
285 095 160 084 344 110 114 000 047 078
240 136 131 040 389 064 083 047 000 118
356 017 247 155 423 181 117 078 118 000
output:
1069
*/

#include <iostream>
#include <string.h>

using namespace std;

long long matrix[20][20] = { 0 };
int visit[15] = { 0 };
long long result = 999999999999999999;
long long smin = 999999999999999999;

int minFromA(int x, int n)
{
    int res = 0;
    int flag = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            if (flag) {
                res = i;
                flag = false;
            }
            else if (matrix[x][res] > matrix[x][i]) {
                res = i;
            }
        }
    }
    return res;
}

int greedy(int init, int n)
{
    int start = init;		//start = 0
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int next = minFromA(start, n);
        visit[next] = 1;

        res += matrix[start][next];
        start = next;
    }
	memset(visit, 0, sizeof(visit));
    return res + matrix[start][0];
}

void DFS(int x, int n, long long sum, int count)
{
    if (count == n) {
        result = min(result, sum + matrix[x][0]);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0 && (sum + matrix[x][i] + (n - count)*smin < result)) {
            visit[i] = 1;
            DFS(i, n, sum + matrix[x][i], count + 1);
            visit[i] = 0;
        }
    }
}


int main()
{
	freopen("input.txt","r",stdin);
    //input
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
            if(i != 0 && i != j){
            	smin = min(smin, matrix[i][j]);
			}
        }
    }
    //handle
    result = greedy(0, n);
	DFS(0, n, 0, 0);
    //show output
    cout << result;

    return 0;
}
