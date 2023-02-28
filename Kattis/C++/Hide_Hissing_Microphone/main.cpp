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

  for (i64 i = 0; i < s.size() - 1; i++) {
    if (s[i] == 's' && s[i + 1] == 's') {
      cout << "hiss" << endl;
      return 0;
    }
  }

  cout << "no hiss" << endl;

  return 0;
}