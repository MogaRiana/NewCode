#include <bits/stdc++.h>

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

  i64 t;
  str a, b, c;
  cin >> t;
  getline(cin, c);

  while (t--) {
    getline(cin, a);
    getline(cin, b);

    i64 nr1 = a[0] - '0', nr2 = b[0] - '0';
    for (i64 i = 1; i < max(a.size(), b.size()); i++) {
      if (a.size() <= b.size()) {
        if (i < a.size() && a[i] != ' ') {
          nr1 = nr1 * 10 + (a[i] - '0');
        }

        if (b[i] != ' ') {
          nr2 = nr2 * 10 + (b[i] - '0');
        }
      } else {
        if (i < b.size() && b[i] != ' ') {
          nr2 = nr2 * 10 + (b[i] - '0');
        }
        if (a[i] != ' ') {
          nr1 = nr1 * 10 + (a[i] - '0');
        }
      }
    }

    i64 res = nr1 + nr2;
    str ss = to_string(res);

    for (i64 i = 0; i < ss.size(); i++) {
      cout << ss[i] << " ";
    }

    cout << endl;
  }

  return 0;
}