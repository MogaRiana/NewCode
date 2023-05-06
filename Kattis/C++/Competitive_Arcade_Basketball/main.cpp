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

  i64 n, p, m;
  cin >> n >> p >> m;

  map<string, pair<i64, bool>> res;
  for (i64 i = 0; i < n; i++) {
    str s;
    cin >> s;
    res[s] = {0, true};
  }

  bool ok = true;
  for (i64 i = 0; i < m; i++) {
    i64 nr;
    str s;

    cin >> s >> nr;
    res[s].first += nr;

    if (res[s].first >= p && res[s].second) {
      res[s].second = false;
      ok = false;
      cout << s << " wins!" << endl;
    }
  }

  if (ok) {
    cout << "No winner!" << endl;
  }

  return 0;
}