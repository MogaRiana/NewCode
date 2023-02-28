#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 make_num(str s) {
  i64 num = s[0] - 48;
  for (i64 i = 1; i < s.size(); i++) {
    num = num * 10 + (s[i] - 48);
  }

  return num;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 n;
  cin >> n;

  for (i64 i = 1; i <= n; i++) {
    str s;
    cin >> s;

    if (s != "mumble") {
      if (make_num(s) != i) {
        cout << "something is fishy" << endl;
        return 0;
      }
    }
  }

  cout << "makes sense" << endl;

  return 0;
}