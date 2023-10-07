#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  while (s.size() > 1) {
    int a = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '0') {
        a = a * (s[i] - '0');
      }
    }

    s = to_string(a);
  }

  cout << s << endl;

  return 0;
}
