#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

const vi64 dirx = {0, 0, 1, -1};
const vi64 diry = {-1, 1, 0, 0};
deque<p64> fire;

bool ver(i64 r, i64 c, p64 p) {
  i64 x = p.first, y = p.second;
  if (x >= 0 and x < r and y >= 0 and y < c) {
    return true;
  }

  return false;
}

void update(vector<vector<char>> &g) {
  i64 r = g.size(), c = g.front().size();
  deque<p64> q = fire;
  fire.clear();

  while (!q.empty()) {
    p64 p = q.front();
    q.pop_front();

    for (i64 i = 0; i < 4; i++) {
      i64 x = p.first + dirx[i], y = p.second + diry[i];
      if (ver(r, c, {x, y})) {
        g[x][y] = 'F';
        fire.push_back({x, y});
      }
    }
  }
}

i64 solve(vector<vector<char>> &g, p64 st) {
  i64 l = g.size(), c = g.front().size();
  vector<vector<bool>> visit(l, vector<bool>(c, false));
  vv steps(l, vi64(c, 1e9));
  steps[st.first][st.second] = 1;
  visit[st.first][st.second] = true;

  deque<p64> p;
  p.push_back({st});

  while (!p.empty()) {
    deque<p64> q = p;
    p.clear();

    while (!q.empty()) {
      p64 pp = q.front();
      q.pop_front();

      i64 xx = pp.first;
      i64 yy = pp.second;

      if ((xx == 0 or xx == l - 1 or yy == 0 or yy == c - 1) and
          g[xx][yy] == '.') {
        return steps[xx][yy];
      }

      for (i64 i = 0; i < 4; i++) {
        i64 x = xx + dirx[i], y = yy + diry[i];
        if (ver(l, c, {x, y}) and !visit[x][y] and g[xx][yy] == '.') {
          visit[x][y] = true;
          steps[x][y] = min(steps[xx][yy] + 1, steps[x][y]);
          p.push_back({x, y});
        }
      }
    }

    update(g);
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 r, c;
  cin >> r >> c;

  p64 start;
  vector<vector<char>> v(r, vector<char>(c));
  for (i64 i = 0; i < r; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> v[i][j];
      if (v[i][j] == 'J') {
        start = {i, j};
        v[i][j] = '.';
      } else if (v[i][j] == 'F') {
        fire.push_back({i, j});
      }
    }
  }

  i64 ans = solve(v, start);
  if (ans == -1) {
    cout << "IMPOSSIBLE" << endl;

  } else {
    cout << ans << endl;
  }

  return 0;
}