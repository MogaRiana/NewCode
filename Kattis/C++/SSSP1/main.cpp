#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

vector<pair<i64, i64>> solve(i64 s, vector<vector<pair<i64, i64>>> &g) {
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>,
                 greater<pair<i64, i64>>>
      pq;
  vector<pair<i64, i64>> ans(g.size() + 1, {1e9, -1});
  ans[s] = {0, -1};
  pq.emplace(0, s);

  while (!pq.empty()) {
    pair<i64, i64> p = pq.top();
    pq.pop();
    i64 dist = p.first;
    i64 node = p.second;

    if (dist > ans[node].first) {
      continue;
    }
    for (auto &c : g[node]) {
      i64 cand = dist + c.second;
      if (cand < ans[c.first].first) {
        ans[c.first] = {cand, node};
        pq.emplace(cand, c.first);
      }
    }
  }

  return ans;
}

int main() {
  i64 n, m, q, s;

  while (cin >> n >> m >> q >> s) {
    if (n == 0 and m == 0 and q == 0 and s == 0) {
      break;
    }

    vector<vector<pair<i64, i64>>> gg(n);
    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;

      gg[u].push_back({v, w});
    }

    vector<pair<i64, i64>> ans = solve(s, gg);
    for (i64 i = 0; i < q; i++) {
      i64 cc;
      cin >> cc;

      if (ans[cc].first == 1e9) {
        cout << "Impossible" << endl;
      } else {
        cout << ans[cc].first << endl;
      }
    }

    cout << endl;
  }

  return 0;
}