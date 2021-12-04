#include <iostream>
#include <string.h>

/*
H�nh ?nh ch?p t? v? tinh v�ng bi?n Atlantic g?m nhi?u h�n d?o du?c chia nh?
th�nh c�c lu?i � vu�ng. M�y quang h?c s? ti?n h�nh qu�t t?ng lu?i � vu�ng, v�
ti?n h�nh t� m�u d? n?u � d� c� ch?a d?t c?a h�n d?o n�o d�, v� t� m�u xanh n?u
kh�ng c� h�n d?o n�o n?m trong n�. H�y:

* �?m s? h�n d?o c� trong ?nh

* �ua ra di?n t�ch c?a h�n d?o l?n nh?t (= s? lu?ng lu?i � vu�ng ch?a h�n d?o
l?n nh?t)

Input
D�ng d?u ti�n ch?a hai s? nguy�n duong n,m<=1000n.

C�c d�ng ti?p theo bi?u di?n lu?i � vu�ng nhu v� d?.

Output
G?m hai d�ng:

D�ng d?u ti�n ch?a s? lu?ng h�n d?o trong ?nh.

D�ng th? hai ch?a di?n t�ch c?a h�n d?o l?n nh?t nhu mi�u t?.

input:
7 11
00000000010
11100000000
00000111100
00111111110
00111111110
00111111000
00000110000

output:
3
28

*/

using namespace std;

char matrix[1001][1001];
int visit[1001][1001] = {0};
int res, count;
void DFS(int x, int y) {
  if (matrix[x][y] == '1' && visit[x][y] == 0) {
    count++;
    visit[x][y] = 1;

    DFS(x + 1, y);
    DFS(x - 1, y);
    DFS(x, y + 1);
    DFS(x, y - 1);
  }
}

int main() {
  // input
  memset(matrix, '0', sizeof(matrix));
  int row, col;
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    cin >> matrix[i];
  }

  // handle
  int soDao = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (matrix[i][j] == '1' && visit[i][j] == 0) {
        soDao++;

        count = 0;
        DFS(i, j);
        res = max(res, count);
      }
    }
  }
  // show output
  cout << soDao << "\n" << res;

  return 0;
}
