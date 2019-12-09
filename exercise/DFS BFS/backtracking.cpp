/*

*/

#include <iostream>

using namespace std;

int n,M;
int sum;
int x[100];
int res = 0;

void show() {
	for(int i=1; i<=n; i++) {
		cout<<x[i]<<" ";
	}
	cout<<"\n";
}
int check(int i,int k) {
	if(k<n) return sum + i < M;
	return sum + i == M;
}

void TRY(int k) {
	if(k==n+1) {
//		show();
		res++;
		return;
	}
	for(int i=1; i<=M; i++ ) {
		if(check(i,k)) {
			x[k] = i;
			sum +=i;
			TRY(k+1);
			sum -=i;
		}
	}
}

int main() {
	n=10;
	M = 20;
	sum = 0;
	TRY(1);
	cout<<res;

	return 0;
}

