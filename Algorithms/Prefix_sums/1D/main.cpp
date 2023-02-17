#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  vi64 v = {0, 1, 6, 11, 9, 7, 5, 20};
  vi64 pref = v;

  for (i64 i = 1; i < v.size(); i++) {
    pref[i] = v[i] + pref[i - 1];
  }

  for (i64 i = 0; i < v.size(); i++) {
    cout << pref[i] << " ";
  }

  return 0;
}