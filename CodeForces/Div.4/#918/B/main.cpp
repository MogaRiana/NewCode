#include <algorithm>
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    char a, b, c;
    for (i64 i = 0; i < 3; i++) {
      cin >> a >> b >> c;

      if (a == '?') {
        if (b != 'A' and c != 'A') {
          cout << 'A' << endl;
        } else if (b != 'B' and c != 'B') {
          cout << 'B' << endl;
        } else if (b != 'C' and c != 'C') {
          cout << 'C' << endl;
        }
      } else if (b == '?') {
        if (a != 'A' and c != 'A') {
          cout << 'A' << endl;
        } else if (a != 'B' and c != 'B') {
          cout << 'B' << endl;
        } else if (a != 'C' and c != 'C') {
          cout << 'C' << endl;
        }
      } else if (c == '?') {
        if (b != 'A' and a != 'A') {
          cout << 'A' << endl;
        } else if (b != 'B' and a != 'B') {
          cout << 'B' << endl;
        } else if (b != 'C' and a != 'C') {
          cout << 'C' << endl;
        }
      }
    }
  }

  return 0;
}
