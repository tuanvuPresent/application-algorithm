/*
Cho 1 m?t hoán v? HH d? dài nn v?i các thành ph?n n?m trong t?p {1,2,…,n}{1,2,…,n}. 
Tìm hoán v? k? ti?p c?a hoán v? HH trong th? t? t? di?n.
 
Input
Dòng d?u ghi 1 s? nguyên duong n=104n=104.
 
Dòng th? 2 ghi nn s? nguyên duong =n=n cách nhau b?i d?u cách là hoán v? HH.
 
Output
Ghi ra hoán v? HH trên m?t dòng duy nh?t, các thành ph?n cách nhau b?i d?u cách. N?u không t?n t?i thì ghi ra -1.
*/
 
#include <iostream>
#include <string.h>
#include <algorithm>
 
using namespace std;
int n, k, arr[10000];
 
void input(){
//	for(int i=0;i<10000;i++) arr[i] = i + 1;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
}
 
void show(int arr[], int n){
	for(int i=0; i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
 
void permute(int a[], int n) {
    while (true) {
        show(a,n);
        int k, l;
        for (k = n-2; k>=0; k--) if (a[k] < a[k+1]) break; // Bu?c 1 : tim k | a[k] < a[k+1]
        if (k<0) break;                                    //
        for (l = n-1; l>k; l--) if (a[k] < a[l]) break; // Bu?c 2 : tim l | a[k] < a[l]
        swap(a[k], a[l]); // Bu?c 3 
        for (int i=k+1, j=n-1; i<j; i++, j--) swap(a[i], a[j]); // Bu?c 4 : Ðao nguoc mang trong doan k+1 -> n - 1  
    }
}
 
bool permuteK(int a[], int n, int k) {
	int count = k;
	bool flag = false;
    while (count--) {
    	flag = false;
        int k, l;
        for (k = n-2; k>=0; k--) if (a[k] < a[k+1]) break; // Bu?c 1 : tim k | a[k] < a[k+1]
        if (k<0) break;                                    
        flag = true;
        for (l = n-1; l>k; l--) if (a[k] < a[l]) break; // Bu?c 2 : tim l | a[k] < a[l]
        swap(a[k], a[l]); // Bu?c 3 
        for (int i=k+1, j=n-1; i<j; i++, j--) swap(a[i], a[j]); // Bu?c 4 : Ðao nguoc mang trong doan k+1 -> n - 1  
    }
    
    return flag;
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	input();
	if(permuteK(arr,n,1))
		show(arr,n);
	else
		cout<<-1;
	return 0;
}
