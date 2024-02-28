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
    i64 n;
    cin >> n;

    vi64 v(n);
    for (auto &i : v) {
      cin >> i;
    }

    i64 sum = 0;
    sort(v.begin(), v.end());
    for (auto &i : v) {
      if (i < 0) {
        sum += -i;
      } else {
        sum += i;
      }
    }

    cout << sum << endl;
  }

  return 0;
}
