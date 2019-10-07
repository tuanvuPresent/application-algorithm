/*

*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char s[10001];

int increase(int n){
	int carry = 1;
	for(int i=n-1;i>=0;i--){
		int temp = s[i] - '0' + carry;
		if(temp > 1){
			s[i] = (char)(temp % 2 + '0');
			carry = 1;
		}else{
			s[i] = (char)(temp + '0');
			carry = 0;
		}
	}
	return carry == 0;
}

int main(){
	int n;cin>>n;
	cin>>s;
	
	if(increase(n)){
		cout<<s;
	}else{
		cout<<"-1";
	}
	
	return 0;
}

