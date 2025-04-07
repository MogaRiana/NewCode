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

const int NMAX = 100000;

void dijkstra(int p, int n, vec<vec<p64>> &g) {
  priority_queue<p64, vp64, greater<p64>> pq;
  vi64 dist(n + 1, 1e9);
  vec<bool> vis(n + 1, false);

  pq.push({0, p});
  dist[p] = 0;

  while (!pq.empty()) {
    int node = pq.top().sd;
    pq.pop();

    if (vis[node]) {
      continue;
    }
    vis[node] = true;

    for (auto &edge : g[node]) {
      if (dist[edge.sd] > dist[node] + edge.ft) {
        dist[edge.sd] = dist[node] + edge.ft;
        pq.push({dist[edge.sd], edge.sd});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"orzeni.in"};
  ofstream cout{"orzeni.out"};

  int n, k;
  cin >> n >> k;

  int a[n + 1];
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[i] = a[i];
  }

  vv g(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        if (j <= k)
          g[j].push_back(i);
        if (x / j <= k && j != x / j)
          g[x / j].push_back(i);
      }
    }
  }

  for (int i = 0; i < n; i++) {
  }

  return 0;
}