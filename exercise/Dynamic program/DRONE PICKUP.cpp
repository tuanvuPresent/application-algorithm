#include<iostream>
#include <algorithm>

using namespace std;

int good[3001];
int enegy[3001];

int f[101][3001];

void solve(int n,int k){
	//initial row 1
//	cout<<f[1][1]<<" ";
	for(int i=2;i<=n;i++){
		if(1 + enegy[1] >= i){
			f[1][i] = good[1] + good[i];
		}
//		cout<<f[1][i]<<" ";
	}
//	cout<<"\n";
	
	for(int i=2;i<=k;i++){
		f[i][1] = 0;
//		cout<<f[i][1]<<" ";
		for(int j=2;j<=n;j++){
			//find max
			int max = 0;
			for(int p=1;p<j;p++){
				if(enegy[p] + p >= j && f[i-1][p] != 0){
					if(max < f[i-1][p]){
						max = f[i-1][p];
					}
				}
			}
			f[i][j] = (max!=0)? max + good[j]:0;
//			cout<<f[i][j]<<" ";
		}
//		cout<<"\n";
	}
}

int main(){
	//input
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>good[i];
	for(int i=1;i<=n;i++) cin>>enegy[i];
	//handle
	solve(n,k);
	//show output
	if(f[k][n]==0){
		cout<<"-1";
	}else{
		cout<<f[k][n];
	}
	
	return 0;
}

