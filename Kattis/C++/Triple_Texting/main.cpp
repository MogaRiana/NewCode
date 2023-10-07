#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

str makecuv(str s, pair<i64, i64> coord) {
  str ss;
  for (i64 i = coord.first; i < coord.second; i++) {
    ss.push_back(s[i]);
  }

  return ss;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  cin >> s;

  i64 cuv = s.size() / 3;
  map<str, i64> m;

  m[makecuv(s, {0, cuv})]++;
  m[makecuv(s, {cuv, 2 * cuv})]++;
  m[makecuv(s, {2 * cuv, 3 * cuv})]++;

  for (auto &x : m) {
    if (x.second == 2 or x.second == 3) {
      cout << x.first << endl;
      return 0;
    }
  }

  cout << s.substr(0, cuv) << endl;

  return 0;
}