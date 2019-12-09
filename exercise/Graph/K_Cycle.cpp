/*
5 7 4
1 2
1 3
2 3
2 4
2 5
3 4
4 5
outputCopy
2
*/

#include<iostream>
#include <algorithm>

using namespace std;
int visit[31] = {0};
int res=0;
int graph[31][31];

void DFS(int k, int n, int v, int start) {
	if(k==1) {
		if(graph[v][start]) {
			res++;
		}
		return;
	}
	visit[v] = 1;
	for(int i=1; i<=n; i++) {
		if(!visit[i] && graph[v][i]) {
			DFS(k-1,n,i,start);
		}
	}
	visit[v] = 0;
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0; i<m; i++) {
		int x,y;
		cin>>x>>y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	//handle
	for(int i=1; i<=n-k+1; i++) {
		DFS(k,n,i,i);
		visit[i] = 1;
	}
	//show output
	cout<<res/2;

	return 0;
}

