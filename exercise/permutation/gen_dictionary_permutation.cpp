/*
Cho 1 m?t ho�n v? HH d? d�i nn v?i c�c th�nh ph?n n?m trong t?p
{1,2,�,n}{1,2,�,n}. T�m ho�n v? k? ti?p c?a ho�n v? HH trong th? t? t? di?n.

Input
D�ng d?u ghi 1 s? nguy�n duong n=104n=104.

D�ng th? 2 ghi nn s? nguy�n duong =n=n c�ch nhau b?i d?u c�ch l� ho�n v? HH.

Output
Ghi ra ho�n v? HH tr�n m?t d�ng duy nh?t, c�c th�nh ph?n c�ch nhau b?i d?u c�ch.
N?u kh�ng t?n t?i th� ghi ra -1.
*/

#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;
int n, k, arr[10001];
long long gt[15];
int choice[10003];

void input() {
  for (int i = 0; i < 10000; i++)
    arr[i] = i + 1;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

void show(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void permute(int a[], int n) {
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
        break;        // Bu?c 2 : tim l | a[k] < a[l]
    swap(a[k], a[l]); // Bu?c 3
    for (int i = k + 1, j = n - 1; i < j; i++, j--)
      swap(a[i], a[j]); // Bu?c 4 : �ao nguoc mang trong doan k+1 -> n - 1
  }
}

void permuteK(int a[], int n, int k) {
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
        break;        // Bu?c 2 : tim l | a[k] < a[l]
    swap(a[k], a[l]); // Bu?c 3
    for (int i = k + 1, j = n - 1; i < j; i++, j--)
      swap(a[i], a[j]); // Bu?c 4 : �ao nguoc mang trong doan k+1 -> n - 1
  }

  if (flag) {
    show(a, n);
  } else {
    cout << -1;
  }
}

int factorial(int n) {
  gt[0] = gt[1] = 1;
  for (int i = 2; i <= n; i++) {
    gt[i] = i * gt[i - 1];
  }
}

int findPosition(int k) {
  int i = 1;
  while (k) {
    if (choice[i++] == 0)
      k--;
  }
  return i - 1;
}

void permuteFast(int a[], int n, int k) {
  factorial(15);
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
    if (k % gt[n - i - 1] != 0) {
      x++;
    }

    a[i] = findPosition(x);
    k -= gt[n - i - 1] * (x - 1);

    choice[a[i]] = 1;
    count++;
  }
  // chon lan luot cac so con lai
  for (int i = 1; i <= n; i++) {
    if (choice[i] == 0) {
      a[count++] = i;
    }
  }
  // show
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  input();
  //    permuteFast(arr, n, k);
  permuteK(arr, n, 1);

  return 0;
}
