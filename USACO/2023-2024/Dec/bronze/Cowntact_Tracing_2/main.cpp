#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  str s;
  cin >> n >> s;

  i64 crt = n;
  for (i64 i = 0; i < n; i++) {
    if (s[i] == '0') {
      crt--;
    }
    if (i > 0 and i < n - 1) {

    } else {
      if ((i == 0 and s[i] == s[i + 1]) or (i == 1 and s[i] == s[i - 1])) {
        crt--;
      }
    }
  }

  return 0;
}
