#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i64 n, m;
  cin >> n >> m;
  i64 d = m / n;
  vector<vector<char>> c(n, vector<char>(d, '*'));

  if (m % n != 0) {
    i64 a = m % n;
    for (i64 i = 0; i < a; i++) {
      c[i].push_back('*');
    }
  }

  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < c[i].size(); j++) {
      cout << c[i][j];
    }
    cout << endl;
  }

  return 0;
}
