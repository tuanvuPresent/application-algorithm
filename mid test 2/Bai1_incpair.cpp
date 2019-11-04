/*
input
4
1 3 5 2
output:
4
*/
#include<iostream>
#include <algorithm>

using namespace std;
int arr[1001];

int main(){
	//input
	int n; cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	//
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i] < arr[j]){
				res++;
			}
		}
	}
	
	//show output
	cout<<res;
		
	return 0;
}

