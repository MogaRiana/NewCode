#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i6) x.size()
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

const vi64 dirx = {-1, 1, 0, 0};
const vi64 diry = {0, 0, -1, 1};

bool ver(i64 x, i64 y, i64 n) {
  if (x >= 0 and x < n and y >= 0 and y < n) {
    return true;
  }
  return false;
}

class pulsar {
public:
  i64 x, y, r, t;

  void init(vector<vector<pair<i64, set<i64>>>> &grid, i64 i) {
    grid[x][y].first = -1;
    grid[x][y].second.insert(i);

    deque<p64> q;
    q.push_back({x, y});

    i64 op = 0;
    while (!q.empty()) {
      p64 p = q.front();
      q.pop_front();

      for (i64 k = 0; k < 4; k++) {
        i64 xx = p.ft + dirx[k];
        i64 yy = p.sd + diry[k];

        if (ver(xx, yy, grid.size()) and op < t) {
          grid[xx][yy].first = -1;
          grid[xx][yy].second.insert(i);
          q.push_back({xx, yy});
          op++;
        }

        if (op >= t) {
          q.clear();
          break;
        }
      }
    }
  }

  void up(vector<vector<pair<i64, set<i64>>>> &grid, i64 i) {
    i64 c = 0;
    for (i64 ii = y + 1; ii < grid.size(); ii++) {
      if (grid[x][y + ii].ft == -1 and grid[x][y + ii].sd.count(i)) {
        c++;
      }
    }

    if (c == r - 1) {
      deque<p64> q;
      q.push_back({x, y});

      i64 op = 0;
      while (!q.empty()) {
        p64 p = q.front();
        q.pop_front();

        for (i64 k = 0; k < 4; k++) {
          i64 xx = p.ft + dirx[k];
          i64 yy = p.sd + diry[k];

          if (ver(xx, yy, grid.size()) and op < r - 1 and
              grid[xx][yy].sd.count(i)) {
            grid[xx][yy].ft = 0;
            grid[xx][yy].sd.erase(i);
            q.push_back({xx, yy});
            op++;
          }

          if (op >= r - 1) {
            q.clear();
            break;
          }
        }
      }
    } else {
      i64 x1 = x + c, y1 = y + c;
      i64 x2 = x - c, y2 = y - c;

      vp64 d = {{x1, y}, {x2, y}, {x, y1}, {x, y2}};
      for (i64 ii = 0; ii < 4; ii++) {
        for (i64 k = 0; k < 4; k++) {
          i64 xx = d[ii].ft + dirx[k];
          i64 yy = d[ii].sd + diry[k];

          if (ver(xx, yy, grid.size())) {
            grid[xx][yy].ft = -1;
            grid[xx][yy].sd.insert(i);
          }
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 c, n, pp;
  cin >> c >> n >> pp;

  vector<vector<pair<i64, set<i64>>>> grid(n, vector<pair<i64, set<i64>>>(n));
  vector<pulsar> v(pp);
  for (i64 i = 0; i < pp; i++) {
    cin >> v[i].x >> v[i].y >> v[i].r >> v[i].t;
    v[i].x--;
    v[i].y--;
    v[i].r--;
    v[i].t--;
    v[i].init(grid, i);
  }

  p64 cs, cf;
  cin >> cs.ft >> cs.sd >> cf.ft >> cf.sd;

  vv r(n, vi64(n, 0));

  deque<p64> q;
  q.push_back(cs);

  i64 op = 0;
  while (!q.empty()) {
    p64 p = q.front();
    q.pop_front();

    bool kk = true;
    for (i64 k = 0; k < 4; k++) {
      i64 xx = p.ft + dirx[k];
      i64 yy = p.sd + diry[k];

      if (ver(xx, yy, n)) {
        if (grid[xx][yy].first != -1) {
          r[xx][yy] = r[p.ft][p.sd] + 1;
          q.push_back({xx, yy});
          kk = true;
          if (xx == cf.ft && yy == cf.sd) {
            r[xx][yy] = r[p.ft][p.sd] + 1;
            q.clear();
            break;
          }
        } else {
          kk = false;
        }
      }
    }

    if (!kk) {
      grid[p.ft][p.sd].ft++;
    } else {
      for (i64 i = 0; i < pp; i++) {
        v[i].up(grid, i);
      }
    }
  }

  if (c == 2) {
    cout << r[cf.ft][cf.sd] << endl;
  }

  return 0;
}