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

  double c, s = 0;
  i64 n;
  cin >> c >> n;

  for (i64 i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;
    s += a * b;
  }

  cout.precision(6);
  cout << fixed << s * c << endl;

  return 0;
}