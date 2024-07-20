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

i64 l, c;
const vector<int> dirx = {1, -1, 0, 0};
const vector<int> diry = {0, 0, 1, -1};

bool isValid(i64 x, i64 y) { return x >= 0 && x < l && y >= 0 && y < c; }

i64 bfs(vv &eep, p64 start, i64 y, vec<vec<bool>> visit) {
  i64 crt = 1;
  deque<p64> q;
  q.push_back({start.first, start.second});

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (int i = 0; i < 4; i++) {
      int x = cur.first + dirx[i];
      int y = cur.second + diry[i];
      if (isValid(x, y) and !visit[x][y] and eep[x][y] <= y) {
        q.push_back({x, y});
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

  i64 y;
  cin >> l >> c >> y;

  vv v(l, vi64(c));
  for (auto &row : v) {
    for (auto &cell : row) {
      cin >> cell;
    }
  }

  i64 lvl = 1;
  vec<vec<bool>> sunk(l, vec<bool>(c, false));
  for (i64 lvl = 1; lvl <= y; lvl++) {
    i64 crt = 0;
    vec<vec<bool>> visit(l, vec<bool>(c, false));
    for (i64 xx = 0; xx < l; xx++) {
      for (i64 yy = 0; yy < c; yy++) {
        if (v[xx][yy] <= lvl) {
          if (xx == 0 or xx == l - 1 or yy == 0 or yy == c - 1) {
            sunk[xx][yy] = true;
            crt += bfs(v, {xx, yy}, lvl, visit);
          } else {
            for (i64 d = 0; d < 4; d++) {
              i64 xd = xx + dirx[d];
              i64 yd = yy + diry[d];

              if (isValid(xd, yd) && sunk[xd][yd]) {
                sunk[xx][yy] = true;
                crt += bfs(v, {xx, yy}, lvl, visit);
              }
            }
          }
        }
      }
    }

    cout << l * c - crt << endl;
  }

  return 0;
}