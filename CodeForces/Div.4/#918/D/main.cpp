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
    i64 n;
    str s;
    cin >> n >> s;

    str res = "";
    while (!s.empty()) {
      i64 x;
      if (s.back() == 'a' or s.back() == 'e') {
        x = 2;
      } else {
        x = 3;
      }

      while (x--) {
        res += s.back();
        s.pop_back();
      }

      res += '.';
    }

    res.pop_back();
    reverse(res.begin(), res.end());
    cout << res << endl;
  }

  return 0;
}
