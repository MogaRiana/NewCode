#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
#define endl '\n'

int main() {
  i64 n, k;
  cin >> n >> k;

  i64 minc = 1e9;
  vi64 c(k + 1, 0);

  for (i64 i = 0; i < n; i++) {
    i64 a;
    cin >> a;
    c[a]++;
  }

  for (i64 i = 1; i <= k; i++) {
    minc = min(minc, c[i]);
  }

  vi64 res;
  for (i64 i = 1; i <= k; i++) {
    if (c[i] == minc) {
      res.push_back(i);
    }
  }

  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (i64 i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
}