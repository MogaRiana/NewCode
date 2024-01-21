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

  map<pair<str, str>, i64> teams;
  deque<str> q;
  i64 n;
  cin >> n;
  n -= 4;

  str wo, bo, wd, bd;
  cin >> wo >> bo >> wd >> bd;
  while (n--) {
    str x;
    cin >> x;
    q.push_back(x);
  }

  str score;
  cin >> score;

  i64 crtw = 0, crtb = 0, m = -1e9;
  for (auto &x : score) {
    if (x == 'W') {
      crtw++;
      m = max(m, crtb);
      teams[{bo, bd}] = max(crtb, teams[{bo, bd}]);
      crtb = 0;

      q.push_back(bd);
      swap(bo, bd);
      bo = q.front();
      q.pop_back();
    } else {
      crtb++;
      m = max(m, crtw);
      teams[{wo, wd}] = max(crtb, teams[{wo, wd}]);
      crtw = 0;

      q.push_back(wd);
      swap(wo, wd);
      wo = q.front();
      q.pop_back();
    }
  }

  for (auto &x : teams) {
    if (x.second == m) {
      cout << x.first.first << " " << x.first.second << endl;
    }
  }

  return 0;
}