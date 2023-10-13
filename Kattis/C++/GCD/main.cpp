#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef long double d6;

i64 gcd(i64 a, i64 b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;

  return 0;
}