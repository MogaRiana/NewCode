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

  str s;
  cin >> s;

  vector<double> v(4, 0);
  double ll = s.size();
  for (i64 i = 0; i < s.size(); i++) {
    if (s[i] == '_') {
      v[0]++;
    } else if (s[i] >= 'a' and s[i] <= 'z') {
      v[1]++;
    } else if (s[i] >= 'A' and s[i] <= 'Z') {
      v[2]++;
    } else {
      v[3]++;
    }
  }

  cout.precision(10);
  cout << fixed;
  for (i64 i = 0; i < 4; i++) {
    cout << (100 / ll * v[i]) / 100 << endl;
  }

  return 0;
}