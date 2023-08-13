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
  cin >> n;
  getline(cin, s);

  n = pow(2, n + 1);

  i64 pos = 1;
  for (i64 i = 0; i < s.size(); i++) {
    char dir = s[i];
    if (dir == 'L') {
      pos = pos * 2;
    } else if (dir == 'R') {
      pos = pos * 2 + 1;
    }
  }

  cout << n - pos << endl;

  return 0;
}