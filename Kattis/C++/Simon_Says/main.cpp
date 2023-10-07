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

  i64 t;
  cin >> t;

  for (i64 i = 0; i < t; i++) {
    str s;
    getline(cin, s);
    if (i == 0) {
      getline(cin, s);
    }

    str ss = s.substr(0, 10);
    if (ss == "Simon says") {
      for (i64 j = 11; j < s.size(); j++) {
        cout << s[j];
      }
      cout << endl;
    }
  }

  return 0;
}