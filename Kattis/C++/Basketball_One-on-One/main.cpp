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

  str s;
  i64 a = 0, b = 0;
  bool tie = false;
  cin >> s;

  for (i64 i = 0; i < s.size(); i += 2) {
    if (s[i] == 'A') {
      a += s[i + 1] - '0';
    } else if (s[i] == 'B') {
      b += s[i + 1] - '0';
    }
  }

  if (a > b) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }

  return 0;
}