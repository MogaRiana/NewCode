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

bool cond(const pair<int, str> &a, const pair<int, str> &b) {
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return (a.second < b.second);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    map<str, i64> toys;
    while (n--) {
      str name;
      i64 cnt;
      cin >> name >> cnt;
      toys[name] += cnt;
    }

    vector<pair<i64, str>> res;
    for (auto &x : toys) {
      res.push_back({x.second, x.first});
    }

    sort(res.begin(), res.end(), cond);
    cout << res.size() << endl;
    for (i64 i = 0; i < res.size(); i++) {
      cout << res[i].second << " " << res[i].first << endl;
    }
  }

  return 0;
}