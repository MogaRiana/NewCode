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

  i64 n, s, cc = 0;
  cin >> n >> s;

  vp64 v(n);
  vector<bool> b(n, false);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    if (v[i].first) {
      cc++;
    }
  }

  i64 k = 1, crt = 0, val = 1;
  for (i64 i = s - 1; i < n and i >= 0; i += (val * k)) {
    if (!v[i].first) {
      val += v[i].second;
      k *= -1;
    } else {
      if (val >= v[i].second and !b[i]) {
        crt++;
        b[i] = true;
      }
    }

    if (crt == cc) {
      break;
    }
  }

  cout << crt << endl;

  return 0;
}
