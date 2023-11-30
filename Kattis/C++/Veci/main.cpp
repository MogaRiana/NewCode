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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  cin >> s;
  i64 n = stoi(s);

  i64 res = 1e9;
  while (next_permutation(s.begin(), s.end())) {
    i64 r = stoi(s);

    if (r > n) {
      res = min(res, r);
    }
  }

  if (res == 1e9) {
    cout << 0 << endl;
  } else {
    cout << res << endl;
  }

  return 0;
}