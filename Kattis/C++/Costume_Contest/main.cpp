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
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  map<str, i64> cst;
  for (i64 i = 0; i < n; i++) {
    str s;
    cin >> s;
    cst[s]++;
  }

  i64 ans = 1e9;
  set<pair<i64, str>> win;
  for (auto &x : cst) {
    ans = min(ans, x.second);
    win.insert({x.second, x.first});
  }

  for (auto &x : win) {
    if (x.first == ans) {
      cout << x.second << endl;
    }
  }

  return 0;
}