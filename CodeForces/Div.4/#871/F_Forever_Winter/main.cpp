#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, m;
    cin >> n >> m;

    vv g(n);
    for (i64 i = 0; i < m; i++) {
      i64 a, b;
      cin >> a >> b;

      a--;
      b--;

      g[a].push_back(b);
      g[b].push_back(a);
    }

    vi64 res;
    for (i64 i = 0; i < n; i++) {
      if (g[i].size() > 1) {
        res.push_back(i);
      }
    }

    cout << res.size() - 1 << " " << (n - res.size()) / (res.size() - 1)
         << endl;
  }

  return 0;
}