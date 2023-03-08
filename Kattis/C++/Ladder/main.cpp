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

  double a, b;
  cin >> a >> b;

  double res = a / sin(b * 3.141592653589793 / 180.0);

  cout << ceil(res) << endl;

  return 0;
}