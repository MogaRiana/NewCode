#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  vi64 v = {1, 4, 7, 0, 9, 11, 89, 56, 2};
  sort(v.begin(), v.end());

  i64 num;
  while (cin >> num) {
    bool notfound = true;
    i64 l = 0, r = v.size() - 1;

    while (l <= r) {
      i64 mid = l + (r - l) / 2;

      if (v[mid] == num) {
        cout << "found " << num << "at pos: " << mid << endl;
        notfound = false;
        break;
      } else if (v[mid] < num) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    if (notfound) {
      cout << "the number: " << num << " doesn't exist in the vector" << endl;
    }
  }

  return 0;
}