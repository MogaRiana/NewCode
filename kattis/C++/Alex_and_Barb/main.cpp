#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  i64 k, a, b;
  bool at = true, bt = false;
  cin >> k >> a >> b;

  while (k >= 0) {
    if (at) {
      k -= a;
      at = false;
      bt = true;
      continue;
    }
    if (bt) {
      k -= b;
      at = true;
      bt = false;
      continue;
    }
  }

  if (at) {
    cout << "Alex" << endl;
  } else {
    cout << "Barb" << endl;
  }

  return 0;
}
