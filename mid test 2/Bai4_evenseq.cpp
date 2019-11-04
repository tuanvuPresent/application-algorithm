/*
5
-2 1 -4 4 9

ouput:
10
*/
#include <iostream>

using namespace std;

int arr[100001];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	arr[i] += arr[i-1];
	} 
	
	int res = -1000000;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			int sum = arr[j] - arr[i];
			if(sum % 2 ==0){
				if(res < sum){
					res = sum;
				}
			}
		}
	}
    cout<<res;

    return 0;
}

