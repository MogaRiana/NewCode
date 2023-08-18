#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<i32> vi32;
typedef vector<vi64> vv;
typedef vector<vector<i32>> vv32;
typedef string str;

str makestr(str &s) {
  str res;
  for (i32 i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      res.push_back(s[i] - 32);
    } else {
      res.push_back(s[i] + 32);
    }
  }

  return res;
}

map<char, pair<i32, vector<pair<i32, i32>>>> buildmap(str &s) {
  map<char, pair<i32, vector<pair<i32, i32>>>> res;
  for (i32 i = 0; i < s.size(); i++) {
    res[s[i]].first++;
    res[s[i]].second.push_back({i, res[s[i]].first});
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i32 k, q;
  str s;
  cin >> k >> q >> s;

  str sc = makestr(s);
  str next = s + sc + sc + s;

  map<char, pair<i32, vector<pair<i32, i32>>>> m = buildmap(next);

  while (q--) {
    i32 n;
    cin >> n;
    n--;

    if (n < next.size()) {
      char r1 = next[n];
      // i32 r2 = m[r1].second;
      cout << r1;
    }
  }

  return 0;
}