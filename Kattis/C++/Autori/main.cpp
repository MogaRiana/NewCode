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
  cin >> s;

  cout << s[0];
  for (i64 i = 1; i < s.size(); i++) {
    if (s[i] == '-') {
      cout << s[++i];
    }
  }

  return 0;
}