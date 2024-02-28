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

void dof(vector<vector<char>> &g, vv &f) {
  i64 r = g.size(), c = g.front().size();
  deque<p64> q = fire;
  fire.clear();

  while (!q.empty()) {
    i64 xx = q.front().first, yy = q.front().second;
    q.pop_front();

    for (i64 i = 0; i < 4; i++) {
      i64 x = xx + dirx[i], y = yy + diry[i];
      if (ver(r, c, {x, y}) and g[x][y] == '.' and f[x][y] == 1e9) {
        f[x][y] = f[xx][yy] + 1;
        q.push_back({x, y});
      }
    }
  }
}

i64 solve2(vv &f, vector<vector<char>> &g, p64 st) {
  i64 l = g.size(), c = g.front().size();
  vv steps(l, vi64(c, 1e9));
  steps[st.first][st.second] = 0;

  dof(g, f);

  i64 sol = 1e9;
  deque<p64> q;
  q.push_back(st);

  while (!q.empty()) {
    p64 pp = q.front();
    q.pop_front();

    i64 xx = pp.first;
    i64 yy = pp.second;

    for (i64 i = 0; i < 4; i++) {
      i64 x = xx + dirx[i], y = yy + diry[i];
      if (ver(l, c, {x, y}) and steps[x][y] == 1e9 and g[x][y] == '.') {
        if (f[x][y] > steps[xx][yy] + 1) {
          steps[x][y] = steps[xx][yy] + 1;
          q.push_back({x, y});
          if (x == 0 or x == l - 1 or y == 0 or y == c - 1) {
            sol = min(sol, steps[x][y]);
          }
        }
      }
    }
  }

  return sol;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 r, c;
  cin >> r >> c;

  p64 start;
  vector<vector<char>> v(r, vector<char>(c));
  vv f(r, vi64(c, 1e9));
  for (i64 i = 0; i < r; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> v[i][j];
      if (v[i][j] == 'J') {
        start = {i, j};
        v[i][j] = '.';
      } else if (v[i][j] == 'F') {
        fire.push_back({i, j});
        f[i][j] = 0;
      }
    }
  }

  if (start.first == 0 or start.first == r - 1 or start.second == 0 or
      start.second == c - 1) {
    cout << 1 << endl;
    return 0;
  }

  i64 ans = solve2(f, v, start);
  if (ans == 1e9) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans + 1 << endl;
  }

  return 0;
}
