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

  map<char, i64> m;
  str s;
  cin >> s;

  for (i64 i = 0; i < s.size(); i++) {
    m[s[i]]++;
  }

  i64 p = 0, i = 0;
  for (auto &x : m) {
    if (x.second % 2 == 0) {
      p++;
    } else {
      i++;
    }
  }

  return 0;
}