#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 sum(char c) {
  if (c == 'a' or c == 'b' or c == 'c') {
    return 2;
  } else if (c == 'd' or c == 'e' or c == 'f') {
    return 3;
  } else if (c == 'g' or c == 'h' or c == 'i') {
    return 4;
  } else if (c == 'j' or c == 'k' or c == 'l') {
    return 5;
  } else if (c == 'm' or c == 'n' or c == 'o') {
    return 6;
  } else if (c == 'p' or c == 'q' or c == 'r' or c == 's') {
    return 7;
  } else if (c == 't' or c == 'u' or c == 'v') {
    return 8;
  } else if (c == 'w' or c == 'x' or c == 'y' or c == 'z') {
    return 9;
  }
}

i64 number(str &s) {
  i64 res = 0;
  for (i64 i = 0; i < s.size(); i++) {
    res += sum(s[i]);
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  map<str, i64> m;
  for (i64 i = 0; i < n; i++) {
    str s;
    cin >> s;

    m[s] = number(s);
  }

  str s;
  cin >> s;

  i64 nr = 0;
  for (i64 i = 0; i < s.size(); i++) {
    nr += s[i] - '0';
  }

  i64 res = 0;
  for (auto &x : m) {
    if (x.second == nr) {
      res++;
    }
  }

  cout << res << endl;

  return 0;
}