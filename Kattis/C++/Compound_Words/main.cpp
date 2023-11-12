#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef long double d6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  set<str> a;
  vector<str> v;

  while (getline(cin, s)) {
    str ss;
    i64 c = v.size();

    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] == ' ' or s[i] == '/') {
        v.push_back(ss);
        ss.clear();
      } else {
        ss += s[i];
      }
    }
    v.push_back(ss);
  }

  for (i64 i = 0; i < v.size(); i++) {
    for (i64 j = 0; j < v.size(); j++) {
      if (v[i] != v[j]) {
        a.insert(v[i] + v[j]);
      }
    }
  }

  for (auto &x : a) {
    cout << x << endl;
  }

  return 0;
}