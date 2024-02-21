#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    str s;
    cin >> s;

    i64 a = 0, b = 0;
    for (i64 i = 0; i < 5; i++) {
      if (s[i] == 'A') {
        a++;
      } else if (s[i] == 'B') {
        b++;
      }
    }

    (a > b) ? cout << 'A' << endl : cout << 'B' << endl;
  }

  return 0;
}