#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  vi64 a = {2, 4, 8, 10, 11};
  vi64 b = {3, 5, 6, 9};
  vi64 c(a.size() + b.size());

  i64 i = 0, j = 0, k = 0;

  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      c[k] = a[i];
      k++;
      i++;
    } else {
      c[k] = b[j];
      k++;
      j++;
    }
  }
  while (i < a.size()) {
    c[k] = a[i];
    k++;
    i++;
  }
  while (j < b.size()) {
    c[k] = b[j];
    k++;
    j++;
  }

  for (i64 l = 0; l < 9; l++) {
    cout << c[l] << " ";
  }

  return 0;
}