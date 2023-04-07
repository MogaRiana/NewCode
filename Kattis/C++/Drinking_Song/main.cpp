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

  i64 n;
  str s;
  cin >> n >> s;

  while (n) {

    if (n == 1) {
      cout << n << " bottle of " << s << " on the wall, " << n << " bottle of "
           << s << "." << endl;
    } else {
      cout << n << " bottles of " << s << " on the wall, " << n
           << " bottles of " << s << "." << endl;
    }

    n--;
    if (n == 0) {
      cout << "Take it down, pass it around, no more bottles of " << s << "."
           << endl;
    } else if (n == 1) {
      cout << "Take one down, pass it around, " << n << " bottle of " << s
           << " on the wall." << endl;
    } else {
      cout << "Take one down, pass it around, " << n << " bottles of " << s
           << " on the wall." << endl;
    }

    cout << endl;
  }

  return 0;
}