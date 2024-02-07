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

  map<str, pair<i64, str>> list;
  for (i64 i = 0; i < n; i++) {
    str name, date;
    i64 fav;
    cin >> name >> fav >> date;

    if (!list.count(date)) {
      list[date] = {fav, name};
    } else {
      if (fav > list[date].first) {
        list[date] = {fav, name};
      }
    }
  }

  set<str> res;
  for (auto &x : list) {
    res.insert(x.second.second);
  }

  cout << res.size() << endl;
  for (auto &x : res) {
    cout << x << endl;
  }

  return 0;
}