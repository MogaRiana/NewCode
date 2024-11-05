#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int power_of_two(int n) {
  int crt = 1;
  while (crt < n) {
    crt *= 2;
  }

  return crt * 2;
}

class SegmentTree {
private:
  int n;
  vector<int> tree;
  int len;

  void build(vector<i64> &tr) {
    for (int i = 0; i < n; i++) {
      tree[i + len] = tr[i];
    }

    int start = len / 2;
    int end = len;
    while (start != 0) {
      for (int index = start; index < end; index++) {
        tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
      }
      start /= 2;
      end /= 2;
    }
  }

public:
  SegmentTree(vi64 &tr) {
    n = tr.size();
    tree.resize(power_of_two(n), 0);
    len = tree.size() / 2;
    build(tr);
  }

  int query(int l, int r) {
    l = l + len - 1;
    r = r + len - 1;
    int res = -1;

    while (l <= r) {
      if (l % 2 == 1) {
        res = min(res, tree[l]);
        l++;
      }
      if (r % 2 == 0) {
        res = min(res, tree[r]);
        r--;
      }
      r /= 2;
      l /= 2;
    }

    return res;
  }
};

vi64 height, euler, first;
vector<bool> visited;
void dfs(vv &adj, int node, int h = 0) {
  visited[node] = true;
  height[node] = h;
  first[node] = euler.size();
  euler.push_back(node);
  for (auto to : adj[node]) {
    if (!visited[to]) {
      dfs(adj, to, h + 1);
      euler.push_back(node);
    }
  }
}

str s;

bool bfs(vv &p, i64 st, i64 fn, char prf) {
  deque<i64> q;
  q.push_back(st);

  while (!q.empty()) {
    i64 cur = q.front();
    q.pop_front();

    if (cur == fn) {
      if (s[cur] == prf) {
        return true;
      } else {
        return false;
      }
    }

    for (i64 to : p[cur]) {
      if (s[to - 1] == prf) {
        return true;
      }
      if (!visited[to]) {
        visited[to] = true;
        q.push_back(to);
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;
  cin >> n >> m;
  cin >> s;

  vv g(n + 1);
  vv p(n + 1);
  for (i64 i = 0; i < n; i++) {
    i64 u, v;
    cin >> u >> v;

    p[v].push_back(u);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  visited.resize(n + 1, false);
  height.resize(n + 1, 0);
  dfs(g, 1, 0);

  SegmentTree quer(height);

  while (m--) {
    i64 u, v;
    char prf;
    cin >> u >> v >> prf;

    i64 a = quer.query(u, v);
    bool ans1 = bfs(p, u, a, prf);
    bool ans2 = bfs(p, v, a, prf);

    cout << (ans1 or ans2) ? '1' : '0';
  }

  return 0;
}