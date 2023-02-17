#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

vi64 bubblesort(vi64 &a) {
  for (i64 i = 0; i < a.size() - 1; i++) {
    for (i64 j = 0; j < a.size() - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }

  return a;
}

int main() {
  vi64 a = {64, 25, 12, 22, 11};
  vi64 sorted = bubblesort(a);

  for (i64 i = 0; i < sorted.size(); i++) {
    cout << sorted[i] << " ";
  }

  return 0;
}