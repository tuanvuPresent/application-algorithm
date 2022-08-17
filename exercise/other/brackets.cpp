#include <iostream>

using namespace std;

char stack[10000];
int top = -1;

void add(char x) {
  top++;
  stack[top] = x;
}

char pop() {
  int x = top;
  top--;
  return stack[x];
}

char pick() { return stack[top]; }

char swap(char c) {
  if (c == '(')
    return ')';
  if (c == '[')
    return ']';
  if (c == '{')
    return '}';
}

int main() {
  int n;
  scanf("%d\n", &n);
  char s[10000];
  for (int tCase = 0; tCase < n; tCase++) {
    // input
    scanf("%[^\n]%*c", s);
    // handle
    top = -1;
    int res = 1;
    int i = 0;
    while (s[i] != '\0') {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        add(s[i]);
      } else if (top == -1) {
        res = 0;
        break;
      } else if (s[i] != swap(pop())) {
        res = 0;
        break;
      }
      i++;
    }
    // show output
    cout << res << "\n";
  }

  return 0;
}
