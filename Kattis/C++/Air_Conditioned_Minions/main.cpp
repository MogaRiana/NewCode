#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool verify(pair<i64, i64> a, pair<i64, i64> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  vector<pair<i64, i64>> v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end(), verify);
  i64 res = 1, t = v[0].second;
  for (i64 i = 1; i < n; i++) {
    if (v[i].first > t) {
      t = v[i].second;
      res++;
    }
  }

  cout << res << endl;

  return 0;
}