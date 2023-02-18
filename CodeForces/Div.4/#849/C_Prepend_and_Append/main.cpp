#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, size = 0;
    string s;
    deque<i64> d;
    cin >> n >> s;

    for (i64 i = 0; i < n; i++) {
      d.push_back(s[i] - 48);
    }

    while (n) {
      if ((d[0] == 1 && d[d.size() - 1] == 0) ||
          (d[0] == 0 && d[d.size() - 1] == 1)) {
        d.pop_back();
        d.pop_front();
        size = d.size();
        n -= 2;
      } else {
        size = d.size();
        break;
      }
    }

    cout << size << endl;
  }

  return 0;
}