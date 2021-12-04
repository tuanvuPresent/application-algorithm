/*

V�o dau hoc ky, truong ph�ng khoa hoc m�y t�nh D phai ph�n c�ng c�c kh�a hoc cho
gi�o vi�n mot c�ch c�n bang. Khoa D c� m gi�o vi�n T = {1,2, ..., m} v� n kh�a C
= {1,2, ..., n}. Moi kh�a hoc C c� thoi luong hc. Moi gi�o vi�n c� mot danh s�ch
uu ti�n l� danh s�ch c�c kh�a h?c m� anh / c� ay c� the day t�y thuoc v�o chuy�n
m�n cua m�nh. Ch�ng t�i biet mot danh s�ch c�c cap xung dot hai kh�a hoc kh�ng
the duoc chi danh cho c�ng mot gi�o vi�n v� c�c kh�a hoc n�y d� duoc l�n lich
trong c�ng mot thoi gian bieu. Th�ng tin xung dot n�y duoc bieu thi bang ma tran
xung dot A trong d� A (i, j) = 1 chi ra rang kh�a hoc i v� j l� xung dot. Tai
cua gi�o vi�n l� tung thoi luong cua c�c kh�a hoc duoc g�n cho c� ay / anh ay.
L�m the n�o de g�n c�c kh�a hoc nn cho m gi�o vi�n sao cho moi kh�a hoc duoc chi
danh cho mot gi�o vi�n nam trong danh s�ch uu ti�n cua anh ay / c� ay, kh�ng c�
hai kh�a hoc xung dot n�o duoc g�n cho c�ng mot gi�o vi�n v� tai toi da cua gi�o
vi�n l� toi thieu.

input:
4 2
3 7 2 1
2 1 2
2 1 2
2 1 2
2 1 2
0 0 0 1
0 0 0 0
0 0 0 1
1 0 1 0

ouput:
8

*/

#include <iostream>
using namespace std;
int soGiaoVien;
int soMon;
int p[21][6] = {0}; // mon i co nhung giao vien nao day
int time[21];       // thoi gian cua mon
int matrix[21][21]; // matrix[i][j] = 1  ,i  j la 2 mon cung thoi gian day

int res = 1000000000;
int load[6] = {0};
int X[21] = {0};

int maxLoad() {
  int max = load[1];
  for (int i = 2; i <= soGiaoVien; i++) {
    if (max < load[i]) {
      max = load[i];
    }
  }
  return max;
}

int check(int n, int v) {
  if (p[n][v] == 0)
    return 0; // mon n giao vien v day
  for (int i = 1; i <= n - 1; i++) {
    if (matrix[i][n] && X[i] == v)
      return 0;
  }
  return 1;
}

void backtrack(int n) {
  if (n == soMon + 1) {
    int temp = maxLoad();
    res = min(res, temp);
  } else {
    for (int v = 1; v <= soGiaoVien; v++) {
      if (check(n, v)) {
        X[n] = v;
        load[v] += time[n];
        backtrack(n + 1);
        load[v] -= time[n];
      }
    }
  }
}

int main() {
  // input
  cin >> soMon >> soGiaoVien;
  for (int i = 1; i <= soMon; i++)
    cin >> time[i];

  for (int i = 1; i <= soMon; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      p[i][x] = 1;
    }
  }

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
