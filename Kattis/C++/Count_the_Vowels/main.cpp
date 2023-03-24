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

  i64 crt = 0;
  str s;
  getline(cin, s);

  for (i64 i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
        s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
        s[i] == 'u' || s[i] == 'U') {
      crt++;
    }
  }

  cout << crt << endl;

  return 0;
}