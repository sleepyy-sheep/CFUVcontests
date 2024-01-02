#include <iostream>
using namespace std;

int main() {
  string s;
  cin>> s;
  s.append("a");

  int len = 1;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i-1]) {
      len++;
      continue;
    }
    if (s[i] != s[i-1]) {
      cout << s[i-1];
      if (len > 1)
        cout << len;

      s[i-1] = s[i];
      len = 1;
    }

  }
return 0;
}
