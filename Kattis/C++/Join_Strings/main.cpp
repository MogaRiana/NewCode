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

  i64 n;
  cin >> n;

  unordered_map<i64, list<char>> m;
  m.reserve(2 * n);
  for (i64 i = 1; i <= n; i++) {
    str s;
    cin >> s;

    for (i64 j = 0; j < s.size(); j++) {
      m[i].push_back(s[j]);
    }
  }

  for (i64 cc = 0; cc < n - 1; cc++) {
    i64 a, b;
    cin >> a >> b;

    m[a].splice(m[a].end(), m[b]);
    m.erase(b);
  }

  list<char> ll = (*m.begin()).second;
  for (auto &x : ll) {
    cout << x;
  }

  return 0;
}
