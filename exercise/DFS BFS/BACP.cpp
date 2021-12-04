/*
BACP l� thi?t k? m?t chuong tr�nh h?c c�n b?ng b?ng c�ch g�n th?i gian cho c�c
kh�a h?c theo c�ch m� kh?i lu?ng h?c t?p c?a t?ng th?i k? du?c c�n b?ng. C� c�c
kh�a h?c 1,2, LO, N ph?i du?c ch? d?nh cho M giai do?n 1,2, t?m, M. M?i kh�a h?c
t�i c� t�n d?ng v� c� m?t s? kh�a h?c l� di?u ki?n ti�n quy?t. T?i tr?ng c?a m?t
kho?ng th?i gian du?c x�c d?nh l� t?ng s? t�n ch? c?a c�c kh�a h?c du?c g�n cho
giai do?n d�. Th�ng tin ti�n quy?t du?c th? hi?n b?ng ma tr?n AN � N trong d�
Ai, j = 1 ch? ra r?ng c�c kh�a h?c ii ph?i du?c g�n cho m?t kho?ng th?i gian
tru?c kho?ng th?i gian m� kh�a h?c jj du?c ch? d?nh.
T�nh to�n b�i t?p sao cho t?i t?i da cho t?t c? c�c giai do?n l� t?i thi?u.

�?u v�o
D�ng 1 ch?a NN v� MM (2=N=16,2=M=52=N=16,2=M=5)
D�ng 2 ch?a c1, c2, t?m, c
D�ng i + 2 (i = 1, B?n, N) ch?a d�ng th? i c?a ma tr?n A
�?u ra
D�ng duy nh?t ch?a t?i t?i da d� cho t?t c? c�c giai do?n c?a gi?i ph�p du?c t�m
th?y

input:
6 2
4 4 4 4 2 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
1 0 0 0 0 0

output:
12
*/

#include <iostream>
using namespace std;
int soKy;
int soMon;
int tinChi[17];     // thoi gian cua mon
int matrix[17][17]; // matrix[i][j] = 1  ,i  hoc truoc j

int res = 1000000000;
int load[6] = {0};
int X[17] = {0};

int maxLoad() {
  int max = load[1];
  for (int i = 2; i <= soKy; i++) {
    if (max < load[i]) {
      max = load[i];
    }
  }
  return max;
}

int check(int n, int v) {
  for (int i = 1; i <= n - 1; i++) {
    if (matrix[i][n]) {
      if (X[i] >= v)
        return 0;
    } else if (matrix[n][i]) {
      if (X[i] <= v)
        return 0;
    }
  }

  return 1;
}

void backtrack(int n) {
  if (n == soMon + 1) {
    int temp = maxLoad();
    res = min(res, temp);
  } else {
    for (int v = 1; v <= soKy; v++) {
      if (check(n, v)) {
        X[n] = v;
        load[v] += tinChi[n];
        backtrack(n + 1);
        load[v] -= tinChi[n];
      }
    }
  }
}

int main() {
  // input
  cin >> soMon >> soKy;
  for (int i = 1; i <= soMon; i++)
    cin >> tinChi[i];

  for (int i = 1; i <= soMon; i++) {
    for (int j = 1; j <= soMon; j++) {
      cin >> matrix[i][j];
    }
  }
  // handle
  backtrack(1);
  // show output
  if (res == 1000000000) {
    cout << "-1";
  } else {
    cout << res;
  }

  return 0;
}
