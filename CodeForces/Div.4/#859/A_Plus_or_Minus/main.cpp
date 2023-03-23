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

  i64 n;
  cin >> n;

  while (n--) {
    i64 a, b, c;
    cin >> a >> b >> c;

    if (a + b == c) {
      cout << "+" << endl;
    } else {
      cout << "-" << endl;
    }
  }

  return 0;
}