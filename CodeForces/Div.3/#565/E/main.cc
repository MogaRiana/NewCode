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

i64 r = 0, b = 0;
vi32 col;

void bfs(vv &g, int st) {
  r = 0;
  b = 0;

  queue<i64> q;
  q.push(st);
  col[st] = 0;
  r++;

  while (!q.empty()) {
    int p = q.front();
    q.pop();

    for (auto x : g[p]) {
      if (col[x] == 1e9) {
        col[x] = (col[p] + 1) % 2;
        q.push(x);

        if ((col[p] + 1) % 2 == 0) {
          r++;
        } else if ((col[p] + 1) % 2 == 1) {
          b++;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    col.resize(n + 1, 0);
    fill(col.begin(), col.end(), 1e9);
    vv g(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    bfs(g, 1);

    int d = min(r, b), c = 0;
    if (d == r) {
      c = 0;
    } else {
      c = 1;
    }

    cout << d << endl;
    for (int i = 1; i <= n; i++) {
      if (col[i] == c) {
        cout << i << " ";
      }
    }
    cout << endl;
  }

  return 0;
}