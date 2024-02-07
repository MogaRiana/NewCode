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

  set<i64> res;
  for (i64 i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.insert(i - 1);
      res.insert(n / i - 1);
    }
  }

  for (auto &x : res) {
    cout << x << " ";
  }

  return 0;
}