/*
input:
6 2 3
2 5 7 7 2 9
9 8 9 4 8 5
output:
27
*/

#include <iostream>

using namespace std;
int nhiemVu;
int nhanVien;
int k;
int matrix[50][50];

int c[50] = {0};
int res = 1000000000;
int smin = 1000000000;

void backtrack(int n, int sum){
	if(n == nhiemVu + 1){
		if(res > sum) res = sum;
		return;
	}
	for(int i = 1; i <= nhanVien; i++){
		if(c[i] < k && sum + matrix[i][n] + smin * (nhiemVu - n)  < res){
			c[i]++;
			backtrack(n+1, sum + matrix[i][n]);
			c[i]--;
		}
	}
}

int main(){
	//input
	freopen("input.txt.txt","r",stdin);
	cin>>nhiemVu>>nhanVien>>k;
	for(int i = 1; i<= nhanVien; i++){
		for(int j = 1; j <= nhiemVu; j++){
			cin>>matrix[i][j];
			if(smin > matrix[i][j]){
				smin = matrix[i][j];
			}
		}
	}
	
	//handle
	backtrack(1,0);
	//show output
	cout<<res;
	
	return 0;
}

