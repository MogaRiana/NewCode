#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  string s;
  i64 l = 1, r = 1000;
  while (l <= r) {
    i64 mid = l + ((r - l) / 2);
    cout << mid << endl;
    cin >> s;
    if (s == "correct") {
      break;
    } else if (s == "lower") {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return 0;
}