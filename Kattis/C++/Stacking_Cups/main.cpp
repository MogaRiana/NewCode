#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 makedigit(str &s) {
  i64 num = s[0] - 48;
  for (i64 i = 1; i < s.size(); i++) {
    num = num * 10 + (s[i] - 48);
  }

  return num;
}

int main() {
  i64 t;
  cin >> t;
  i64 tc = t;
  map<i64, str> m;
  vi64 v;

  while (tc--) {
    str s1, s2;
    cin >> s1 >> s2;

    if (isdigit(s1[0])) {
      i64 num = makedigit(s1) / 2;
      m[num] = s2;
      v.push_back(num);
    } else {
      i64 num = makedigit(s2);
      m[num] = s1;
      v.push_back(num);
    }
  }

  sort(v.begin(), v.end());

  for (i64 i = 0; i < t; i++) {
    cout << m[v[i]] << endl;
  }

  return 0;
}
