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

struct cow {
  int x, y;
};

i32 n;
vec<cow> c;
bool calc(cow c1, cow c2, int x) {
  // int dist = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
  return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) <= x;
}

int bfs(vv &g, vec<bool> &vis, int st) {
  deq<int> q;
  q.push_back(st);
  vis[st] = true;
  int res = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    vis[u] = true;
    res++;

    for (auto &x : g[u]) {
      if (!vis[x]) {
        vis[x] = true;
        q.push_back(x);
      }
    }
  }

  return res;
}

bool f(int sum) {
  vv g(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (calc(c[i], c[j], sum)) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }

  vec<bool> vis(n, false);
  return n == bfs(g, vis, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"moocast.in"};
  ofstream cout{"moocast.out"};

  cin >> n;

  c.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i].x >> c[i].y;
  }

  int l = 0, r = 1e9;
  int res = 1e9;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (f(mid)) {
      r = mid - 1;
      res = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << res << endl;

  return 0;
}