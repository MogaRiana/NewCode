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

  i64 xk, yk, xo, yo;
  cin >> xk >> yk >> xo >> yo;

  i64 d1 = abs(xo - xk), d2 = abs(yo - yk);
  double dist1 = sqrt(d1 * d1 + d2 * d2);

  cin >> xk >> yk >> xo >> yo;

  d1 = abs(xo - xk);
  d2 = abs(yo - yk);
  double dist2 = sqrt(d1 * d1 + d2 * d2);

  cout.precision(6);
  cout << fixed << max(dist1, dist2) << endl;
  return 0;
}