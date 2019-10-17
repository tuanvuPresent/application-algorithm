/*
2 20
3 2

3
*/

#include<iostream>
#include <algorithm>

using namespace std;

int arr[501];
int f[50001][501];

void solve(int n,int M){
	for(int i=1;i<=M;i++){
		f[i][0] = 1;
		for(int j=1;j<=M;j++){
			if(arr[i] != 0){
				int x = (j-i>=0)?f[i-1][j-i] : 0;
				f[i][j] = x + f[i-1][j];
			}else{
				f[i][j] = f[i-1][j];
			}
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	//input
	int n,M;cin>>n>>M;
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		for(int j=x;j<=500;j+=x){
			arr[j] = 1;
		}
	} 
	//handle
	solve(n,M);
	//show output
	cout<<f[500][M];
	
	return 0;
}

