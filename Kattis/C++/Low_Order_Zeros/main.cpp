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

  vi64 v(1000001);
  i64 ss = 1;
  for (i64 i = 1; i <= 1000000; i++) {
    ss *= i;
    while (ss % 10 == 0) {
      ss /= 10;
    }

    v[i] = ss % 10;
    ss = ss % 10000000;
  }

  i64 n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    cout << v[n] << endl;
  }

  return 0;
}