#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vector<vector<string>> v(3, vector<string>(n));
    map<string, i64> m;

    for (i64 i = 0; i < 3; i++) {
      for (i64 j = 0; j < n; j++) {
        cin >> v[i][j];
        m[v[i][j]]++;
      }
    }

    i64 s1 = 0, s2 = 0, s3 = 0;

    for (i64 i = 0; i < n; i++) {
      if (m[v[0][i]] == 1) {
        s1 += 3;
      } else if (m[v[0][i]] == 2) {
        s1 += 1;
      }
      if (m[v[1][i]] == 1) {
        s2 += 3;
      } else if (m[v[1][i]] == 2) {
        s2 += 1;
      }
      if (m[v[2][i]] == 1) {
        s3 += 3;
      } else if (m[v[2][i]] == 2) {
        s3 += 1;
      }
    }

    cout << s1 << " " << s2 << " " << s3 << endl;
  }

  return 0;
}