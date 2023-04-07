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
  getline(cin, s);

  i64 res = 0;
  for (auto &i : s) {
    res += i;
  }

  cout << char(res / s.size()) << endl;

  return 0;
}