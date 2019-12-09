/*
input:
7 12
1 2
1 3
2 3
2 7
2 4
3 7
3 5
4 7
4 5
4 6
5 6
5 7
*/
#include<iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX 100001
using namespace std;

vector <int> A[MAX];
int N, M;
int visited[100001];
int res[100001];

int check(int x) {
	for(int i=0; i<A[x].size(); i++) {
		if(A[x][i] == 1) return 1;
	}
	return 0;
}

void backtrack(int x, int k, int n) {
	if(k == n) {
		if(check(x)) {
			for(int i=0; i<n; i++) {
				cout<<res[i]<<" ";
			}
			cout<<"\n";
		}
		return;
	}
	for(int i=0; i<A[x].size(); i++) {
		int v = A[x][i];
		if(!visited[v]) {
			visited[v] = 1;
			res[k] = v;
			backtrack(v,k+1,n);
			visited[v] = 0;
		}
	}
}

int main() {
	//input
	cin>>N>>M;
	for(int i=0; i<M; i++) {
		int a,b;
		cin>>a>>b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	//solve
	visited[1] = 1;
	res[0] = 1;
	backtrack(1,1,N);
	//show output

	return 0;
}

