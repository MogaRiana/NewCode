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

    map<str, vi64> m;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      str s;
      cin >> x >> s;

      m[s].push_back(x);
    }

    sort(m["01"].begin(), m["01"].end());
    sort(m["10"].begin(), m["10"].end());
    sort(m["11"].begin(), m["11"].end());

    i64 res = 1e9;
    if (m["01"].size() > 0 && m["10"].size() > 0 && m["11"].size() > 0) {
      cout << min(m["01"].front() + m["10"].front(), m["11"].front()) << endl;
    } else if (m["01"].size() > 0 && m["10"].size() > 0) {
      cout << m["01"].front() + m["10"].front() << endl;
    } else if (m["11"].size() > 0) {
      cout << m["11"].front() << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}