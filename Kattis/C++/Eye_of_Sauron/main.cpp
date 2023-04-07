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

  str s;
  cin >> s;

  i64 crtr = 0, crtl = 0;
  bool b = false;
  for (auto &i : s) {
    if (i != '(' && !b) {
      crtr++;
    } else if (i == '(') {
      b = true;
      i++;
    }

    if (b && i != ')') {
      crtl++;
    }
  }

  if (crtr == crtl) {
    cout << "correct" << endl;
  } else {
    cout << "fix" << endl;
  }

  return 0;
}