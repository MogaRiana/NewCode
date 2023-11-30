#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

pair<i64, i64> d1, d2;

str solve(i64 t) {
  i64 l1 = d1.first + d1.second;
  i64 l2 = d2.first + d2.second;
  i64 r1 = t % l1;
  i64 r2 = t % l2;
  i64 crt = 0;

  if (r1 <= d1.first and r1 != 0) {
    crt++;
  }
  if (r2 <= d2.first and r2 != 0) {
    crt++;
  }

  if (crt == 0) {
    return "none";
  } else if (crt == 1) {
    return "one";
  }
  return "both";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> d1.first >> d1.second >> d2.first >> d2.second;

  for (i64 k = 0; k < 3; k++) {
    i64 t;
    cin >> t;

    cout << solve(t) << endl;
  }

  return 0;
}