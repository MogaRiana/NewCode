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

  map<string, i64> m;
  str s;

  while (getline(cin, s)) {
    if (s == "***") {
      break;
    }

    m[s]++;
  }

  vector<pair<i64, str>> res;
  for (auto &x : m) {
    res.push_back({x.second, x.first});
  }

  sort(res.rbegin(), res.rend());

  if (res[0].first == res[1].first) {
    cout << "Runoff!" << endl;
  } else {
    cout << res[0].second << endl;
  }

  return 0;
}