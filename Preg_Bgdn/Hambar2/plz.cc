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

i16 area(vector<i16> &heights) {
  stack<i16> s;

  i16 max_area = 0;

  for (i16 i = 0; i < heights.size(); i++) {
    while (!s.empty() && heights[i] < heights[s.top()]) {
      i16 height = heights[s.top()];
      s.pop();

      i16 width;
      if (s.empty()) {
        width = i;
      } else {
        width = i - s.top() - 1;
      }
      i16 area = width * height;

      max_area = max(area, max_area);
    }

    s.push(i);
  }

  return max_area;
}

i16 histogram(vector<vector<i16>> &adj) {
  vector<i16> height(adj.size() + 1, 0);

  i16 max_area = 0;
  for (i16 i = 0; i < adj.size(); i++) {
    for (i16 j = 0; j < adj.size(); j++) {
      if (adj[i][j] == 1) {
        height[j] = 0;
      } else {
        height[j]++;
      }
    }

    max_area = max(max_area, area(height));
  }

  return max_area;
}

int main() {
  ifstream cin{"hambar2.in"};
  ofstream cout{"hambar2.out"};

  i16 N, M;
  cin >> N >> M;

  vector<vector<i16>> adj(N, vector<i16>(N, 0));

  for (i16 i = 0; i < M; i++) {
    i16 a, b;
    cin >> a >> b;

    a--, b--;

    if (a >= 0 && b >= 0 && a < N && b < N) {
      adj[a][b] = 1;
    }
  }

  cout << histogram(adj) << '\n';

  return 0;
}