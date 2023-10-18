#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

#define endl '\n'
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
  i64 t, crt = 0;
  cin >> t;

  while (t--) {
    str s;
    cin >> s;

    for (i64 i = 0; i < s.size(); i++) {
      if ((s[i] == 'p' or s[i] == 'r' or s[i] == 'P' or s[i] == 'R') and
          i + 3 < s.size()) {
        str a;
        i64 j;
        for (j = i; j < i + 4; j++) {
          if (s[j] >= 'a' and s[j] <= 'z') {
            a += s[j];
          } else if (s[j] >= 'A' and s[j] <= 'Z') {
            a += s[j] + ('a' - 'A');
          }
        }

        if (a == "pink" or a == "rose") {
          crt++;
          break;
        }
      }
    }
  }

  if (crt) {
    cout << crt << endl;
  } else {
    cout << "I must watch Star Wars with my daughter" << endl;
  }

  return 0;
}