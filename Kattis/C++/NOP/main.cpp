#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool caps(char x) {
  if (x >= 'A' && x <= 'Z') {
    return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str ss;
  cin >> ss;

  i64 res = 0;
  for (i64 i = 1; i < ss.size(); i++) {
    if (caps(ss[i]) && i % 4 != 0) {
      ss.insert(ss.begin() + i, '-');
      res++;
    }
  }

  cout << res << endl;

  return 0;
}