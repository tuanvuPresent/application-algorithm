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
  int wayNumbers[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};
  int numbers[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};

  long long way = 1, number = 0;
  int d;
  while (c > 0 && w > 0) {
    c--;
    d = w % 10;
    w /= 10;
    number += numbers[d];
    way *= wayNumbers[d];
  }

  switch (w % 5) {
  case 0:
    number += w / 5;
    break;
  case 1:
    number += w / 5 + 1;
    if (w != 1)
      way *= 2;
    break;
  case 2:
    number += w / 5 + 1;
    break;
  case 3:
    number += w / 5 + 1;
    break;
  case 4:
    number += w / 5 + 2;
    if (w != 4)
      way *= 3;
    else
      way *= 2;
    break;
  }

  cout << number << " " << way << endl;
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
