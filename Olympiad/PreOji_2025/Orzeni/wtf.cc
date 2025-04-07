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
const i64 INF = 1e18;

int dijkstra(int k, int n, vec<vec<int>> &g) {
  vector<int> prev(n, 1e9), curr(n, 1e9);
  queue<pair<int, pair<int, int>>> pq;

  for (int i : g[2]) {
    prev[i] = 0;
    pq.push({0, {i, 2}});
  }

  int mn = 1e9;
  while (!pq.empty()) {
    auto [cost, state] = pq.front();
    pq.pop();
    int pos = state.first, p = state.second;

    if (p == k) {
      mn = min(mn, cost);
      continue;
    }

    if (cost > curr[pos])
      continue;

    for (int next_pos : g[p + 1]) {
      int new_cost = cost + abs(next_pos - pos);

      if (new_cost < curr[next_pos]) {
        curr[next_pos] = new_cost;
        pq.push({new_cost, {next_pos, p + 1}});
      }
    }

    if (!pq.empty() && pq.front().second.second > p) {
      prev = curr;
      fill(curr.begin(), curr.end(), 1e9);
    }
  }

  return mn;
}

int main() {
  ifstream cin{"orzeni.in"};
  ofstream cout{"orzeni.out"};

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vec<vec<int>> g(k + 1);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        if (j <= k) {
          g[j].push_back(i);
        }
        if (x / j <= k && j != x / j) {
          g[x / j].push_back(i);
        }
      }
    }
  }

  if (k == 1) {
    cout << 0 << '\n';
    return 0;
  }

  for (int p = 2; p <= k; p++) {
    if (g[p].empty()) {
      cout << -1 << "\n";
      return 0;
    }
  }

  int mn = dijkstra(k, n, g);
  if (mn == 1e9) {
    cout << -1 << '\n';
  } else {
    cout << mn << '\n';
  }

  return 0;
}