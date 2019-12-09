/*
inputCopy
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8
outputCopy
3
*/

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v[100001];
int visit[100001];
int res = 0;
int counter = 0;

void isConnect(int n,int x) {
	visit[x] = 1;
	counter++;
	if(counter == n) {
		return;
	}
	for(int i=0; i<v[x].size(); i++) {
		if(visit[v[x][i]] == 0) {
			isConnect(n,v[x][i]);
		}
	}
}

int main() {
	//input
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//handle
	int i=1;
	while(i<=n) {
		while(i<=n && visit[i]) i++;
		if(i<=n) {
			res++;
			isConnect(n,i);
		}
	}
	//how output
	cout<<res;

	return 0;
}

