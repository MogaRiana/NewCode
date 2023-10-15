#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  while (getline(cin, s)) {
    str res = "";
    bool ok = false;
    for (i64 i = 0; i < s.size(); i++) {
      if (i < s.size() - 2 and s[i] == '0' and
          (s[i + 1] == 'X' or s[i + 1] == 'x')) {
        ok = true;
        res += s[i];
        res += s[i + 1];
        i++;
        continue;
      }
      if (ok and
          ((s[i] >= '0' and s[i] <= '9') or (s[i] >= 'a' and s[i] <= 'f') or
           (s[i] >= 'A' and s[i] <= 'F'))) {
        res.push_back(s[i]);
      } else {
        if (ok and res.size() > 2) {
          cout << res << " " << stoi(res, 0, 16) << endl;
        }
        res.clear();
        ok = false;
      }
    }
    if (ok and res.size() > 2) {
      cout << res << " " << stoi(res, 0, 16) << endl;
    }
    res.clear();
    ok = false;
  }

  return 0;
}