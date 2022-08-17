#include <iostream>

using namespace std;

char s1[20], s2[20];

string sum(char a[], char b[]) {
  int lenA = 0, lenB = 0;
  string temp = "", res = "";
  while (a[lenA] != '\0') {
    lenA++;
  }
  while (b[lenB] != 0) {
    lenB++;
  }

  int carry = 0;
  while (lenA > 0 && lenB > 0) {

    int sum = (a[lenA - 1] - '0') + (b[lenB - 1] - '0') + carry;
    if (sum > 9) {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }
    temp += (sum + '0');

    lenA--;
    lenB--;
  }
  while (lenA > 0) {
    int sum = (a[lenA] - '0') + carry;
    if (sum > 9) {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }
    temp += a[lenA - 1];

    lenA--;
  }
  while (lenB > 0) {
    int sum = (b[lenB] - '0') + carry;
    if (sum > 9) {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }
    temp += a[lenB - 1];

    lenB--;
  }
  // dao nguoc chuoi
  temp = (carry == 1) ? temp += '1' : temp;
  int i = 0;
  while (temp[i] != '\0') {
    i++;
  }
  while (i >= 1) {
    res += temp[i - 1];
    i--;
  }
  return res;
}

int main() {
  cin >> s1 >> s2;
  string s = sum(s1, s2);
  cout << s;

  return 0;
}
