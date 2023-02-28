#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  i64 n;
  cin >> n;
  for (i64 i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s == "P=NP") {
      cout << "skipped" << endl;
    } else {
      i64 a = s[0] - 48, b;
      bool oka = true;
      bool okb = false;

      for (i64 i = 1; i < s.size(); i++) {
        if (s[i] == '+') {
          oka = false;
          okb = true;
          b = s[++i] - 48;
          continue;
        }

        if (oka) {
          a = a * 10 + (s[i] - 48);
        }
        if (okb) {
          b = b * 10 + (s[i] - 48);
        }
      }

      cout << a + b << endl;
    }
  }
  return 0;
}
