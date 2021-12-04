/*
inputCopy
2
1000
1
7000
1
outputCopy
1 1
2 1
*/

#include <algorithm>
#include <iostream>

using namespace std;

void atm(long long w, int c) {
  if (w % 1000 != 0) {
    cout << 0 << "\n";
    return;
  } else {
    w /= 1000;
  }
  int so_cach[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};
  int so_to[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};

  long long cach = 1, to = 0;
  int d;
  while (c > 0 && w > 0) {
    c--;
    d = w % 10;
    w /= 10;
    to += so_to[d];
    cach *= so_cach[d];
  }

  switch (w % 5) {
  case 0:
    to += w / 5;
    break;
  case 1:
    to += w / 5 + 1;
    if (w != 1)
      cach *= 2;
    break;
  case 2:
    to += w / 5 + 1;
    break;
  case 3:
    to += w / 5 + 1;
    break;
  case 4:
    to += w / 5 + 2;
    if (w != 4)
      cach *= 3;
    else
      cach *= 2;
    break;
  }

  cout << to << " " << cach << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long w;
    int c;
    cin >> w >> c;
    atm(w, c);
  }

  return 0;
}
