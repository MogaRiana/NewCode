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

  priority_queue<i64> res;
  for (auto &x : occ) {
    res.push(x.second);
  }

  while (k) {
    res.push(res.top() - 1);
    res.pop();
    k--;
  }

  cout << res.top() << endl;

  return 0;
}