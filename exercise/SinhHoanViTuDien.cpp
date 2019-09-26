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
int n, k, arr[10001];
long long gt[15];
int choice[10001];

void input()
{
    for (int i = 0; i < 10000; i++)
        arr[i] = i + 1;
    cin >> n;
    //	for(int i=0;i<n;i++) cin>>arr[i];
}

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void permute(int a[], int n)
{
    while (true) {
        show(a, n);
        int k, l;
        for (k = n - 2; k >= 0; k--)
            if (a[k] < a[k + 1])
                break; // Bu?c 1 : tim k | a[k] < a[k+1]
        if (k < 0)
            break; //
        for (l = n - 1; l > k; l--)
            if (a[k] < a[l])
                break; // Bu?c 2 : tim l | a[k] < a[l]
        swap(a[k], a[l]); // Bu?c 3
        for (int i = k + 1, j = n - 1; i < j; i++, j--)
            swap(a[i], a[j]); // Bu?c 4 : Ðao nguoc mang trong doan k+1 -> n - 1
    }
}

void permuteK(int a[], int n, int k)
{
    int count = k;
    bool flag = false;
    while (count--) {
        flag = false;
        int k, l;
        for (k = n - 2; k >= 0; k--)
            if (a[k] < a[k + 1])
                break; // Bu?c 1 : tim k | a[k] < a[k+1]
        if (k < 0)
            break;
        flag = true;
        for (l = n - 1; l > k; l--)
            if (a[k] < a[l])
                break; // Bu?c 2 : tim l | a[k] < a[l]
        swap(a[k], a[l]); // Bu?c 3
        for (int i = k + 1, j = n - 1; i < j; i++, j--)
            swap(a[i], a[j]); // Bu?c 4 : Ðao nguoc mang trong doan k+1 -> n - 1
    }

    if (flag) {
        show(a, n);
    }
    else {
        cout << -1;
    }
}

int giaiThua(int n)
{
    gt[0] = gt[1] = 1;
    for (int i = 2; i <= n; i++) {
        gt[i] = i * gt[i - 1];
    }
}

int timViTri(int k) {
	int i = 1;
    while(k){
    	if(choice[i] == 0){
    		i++;
    		k--;
		}
	}
	return i - 1;
}

void permuteFast(int a[], int n, int k)
{
	giaiThua(15);
    if (k > gt[n]) {
        cout << -1;
        return;
    }
    // 3 1 2 4 		18 
    // 4 1 2 3		19
    // 4 1 3 2		20
    int count = 0;
    for (int i = 0; i < n && k > 0; i++) {
        int x = k / gt[n - i - 1];
        if (k % gt[n - i - 1] != 0){
            x++;
        }
        
        a[i] = timViTri(x);
        k -= gt[n - i - 1] * (x - 1);
        
        choice[a[i]] = 1;
        count++;
    }
    //chon lan luot cac so con lai
    for (int i = 1; i <= n; i++) {
        if (choice[i] == 0) {
            a[count++] = i;
        }
    }
    //show
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main()
{
    input();
    permuteFast(arr, n, k);
//	permute(arr,n);
//	permuteK(arr,n,k);	

    return 0;
}
