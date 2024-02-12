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

  i64 n, k;
  cin >> n >> k;

  map<i64, i64> occ;
  for (i64 i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    occ[x]++;
  }

  deque<i64> res;
  for (auto &x : occ) {
    res.push_back(x.second);
  }
  sort(res.begin(), res.end());

  while (k) {
    if (res.back() < k) {
      k -= res.back();
      res.pop_back();
    } else {
      res.back() -= k;
      k = 0;
    }
  }

  sort(res.begin(), res.end());
  cout << res.back() << endl;

  return 0;
}