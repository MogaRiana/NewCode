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

  i64 n;
  while (cin >> n) {
    if (n == 0) {
      return 0;
    }

    string ans;
    i64 m;
    i64 t1 = 0, t2 = 0;

    for (i64 i = 0; i < n; i++) {
      cin >> ans >> m;
      if (ans == "DROP") {
        cout << "DROP 2"
             << " " << m << endl;
        t2 += m;
      } else {
        if (t1 >= m) {
          cout << "TAKE 1 " << m << endl;
          t1 -= m;
        } else {
          i64 left = m - t1;
          if (t1 > 0) {
            cout << "TAKE 1 " << t1 << endl;
          }
          t1 = t2;
          cout << "MOVE 2->1 " << t2 << endl;
          t2 = 0;
          cout << "TAKE 1 " << left << endl;
          t1 -= left;
        }
      }
    }
    cout << endl;
  }

  return 0;
}