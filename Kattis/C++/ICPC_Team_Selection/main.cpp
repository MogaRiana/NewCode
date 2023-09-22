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
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    deque<i64> v;
    for (i64 i = 0; i < 3 * n; i++) {
      i64 x;
      cin >> x;
      v.push_back(x);
    }

    sort(v.begin(), v.end());
    i64 res = 0;

    while (!v.empty()) {
      v.pop_back();
      res += v.back();
      v.pop_back();
      v.pop_front();
    }

    cout << res << endl;
  }

  return 0;
}