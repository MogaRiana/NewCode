#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 bfs(vv &tree, i64 n) {
  deque<i64> q;
  q.push_back(n);

  i64 crt = 0;
  while (!q.empty()) {
    i64 k = q.front();
    q.pop_front();

    if (tree[k].size() == 0) {
      return 1;
    }

    for (i64 i = 0; i < tree[k].size(); i++) {
      i64 val = tree[k][i];

      if (tree[val].size()) {
        q.push_back(val);
      } else {
        crt++;
      }
    }
  }

  return crt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vv tree(n + 1, vi64());
    for (i64 i = 0; i < n - 1; i++) {
      i64 u, v;
      cin >> u >> v;

      if (u > v) {
        tree[v].push_back(u);
      }
      if (v > u) {
        tree[u].push_back(v);
      }
    }

    i64 q;
    cin >> q;
    while (q--) {
      i64 x, y;
      cin >> x >> y;

      cout << bfs(tree, x) * bfs(tree, y) << endl;
    }
  }

  return 0;
}