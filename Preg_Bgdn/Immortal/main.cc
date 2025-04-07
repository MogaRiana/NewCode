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

const int NMAX = 21;
int n, m, p;
vp64 v(0);
vec<pair<p64, p64>> res(0);
vec<bool> vis(0);

int grid[NMAX][NMAX];
int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};

bool ok = false;

bool ver(int x, int y) { return x >= 1 and x <= n and y >= 1 and y <= m; }

void solve(int cnt) {
  if (ok)
    return;

  if (cnt == p) {
    ok = true;
    return;
  }

  for (int i = 1; i <= p; i++) {
    if (vis[i])
      continue;

    for (int k = 0; k < 4; k++) {
      int xx = v[i].ft + dirx[k];
      int yy = v[i].sd + diry[k];
      int nxx = xx + dirx[k];
      int nyy = yy + diry[k];

      if (!ver(xx, yy) or !ver(nxx, nyy) or !grid[xx][yy] or grid[nxx][nyy]) {
        continue;
      }

      int victim = grid[xx][yy];
      p64 old_pos = v[i];

      vis[victim] = true;
      grid[xx][yy] = 0;
      grid[old_pos.ft][old_pos.sd] = 0;
      grid[nxx][nyy] = i;
      v[i] = {nxx, nyy};

      res.push_back({old_pos, {nxx, nyy}});
      solve(cnt + 1);
      if (ok) {
        return;
      }

      vis[victim] = false;
      grid[xx][yy] = victim;
      grid[old_pos.ft][old_pos.sd] = i;
      grid[nxx][nyy] = 0;
      v[i] = old_pos;
      res.pop_back();
    }
  }

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"immortal.in"};
  ofstream cout{"immortal.out"};

  cin >> n >> m >> p;
  v.resize(p + 1);
  vis.resize(p + 1, false);

  for (int i = 1; i <= p; i++) {
    int x, y;
    cin >> x >> y;
    grid[x][y] = i;
    v[i] = {x, y};
  }

  solve(1);

  for (auto &x : res) {
    cout << x.ft.ft << " " << x.ft.sd << " " << x.sd.ft << " " << x.sd.sd
         << endl;
  }

  return 0;
}