#include <bits/stdc++.h>

typedef long long i64;
using namespace std;

int main() {
  i64 n;
  cin >> n;

  vector<i64> q;
  q.reserve(100000);
  for (i64 i = 0; i < n; i++) {
    i64 x;
    cin >> x;

    if (!q.empty()) {
      if ((q.back() + x) % 2 == 0) {
        q.pop_back();
      } else {
        q.push_back(x);
      }
    } else {
      q.push_back(x);
    }
  }
  cout << q.size() << endl;
  return 0;
}