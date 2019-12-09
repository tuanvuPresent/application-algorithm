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
#include <set>
#define MAX 100001
using namespace std;

set <int> A[MAX];
stack <int> st,CE;
int N, M;

void solve() {
	st.push(1);
	while(!st.empty()) {
		int x = st.top();
		if(!A[x].empty()) {
			int y = *(A[x].begin());
			st.push(y);
			A[x].erase(y);
			A[y].erase(x);
		} else {
			st.pop();
			CE.push(x);
		}
	}
}

int main() {
	//input
	cin>>N>>M;
	for(int i=0; i<M; i++) {
		int a,b;
		cin>>a>>b;
		A[a].insert(b);
		A[b].insert(a);
	}
	//solve
	solve();
	//show output
	while(!CE.empty()) {
		int x = CE.top();
		CE.pop();
		cout<<x<<" ";
	}

	return 0;
}

