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

map<i64, str> m;

const vi64 dirx = {0, 1, 0, -1};
const vi64 diry = {-1, 0, 1, 0};

bool ver(p64 st, i64 n) {
  if (st.first >= 0 && st.first < n and st.second >= 0 && st.second < n) {
    return true;
  }

  return false;
}

void bfs(vv &grid, vv &r, p64 st, i64 n, i64 c, p64 &res) {
  deq<p64> q;
  q.push_back(st);
  i64 s = 0;

  while (!q.empty()) {
    p64 cur = q.front();
    q.pop_front();

    i64 x = cur.first;
    i64 y = cur.second;
    r[x][y] = c;

    i64 val = grid[x][y];
    for (i64 i = 0; i < 4; i++) {
      if (m[val][i] == '0') {
        i64 xx = x + dirx[i];
        i64 yy = y + diry[i];

        if (ver({xx, yy}, n) and r[xx][yy] == -1) {
          r[xx][yy] = c;
          q.push_back({xx, yy});
          s++;
        }
      }
    }
  }

  if (c != 0) {
    if (s > res.first) {
      res = {s, c};
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"castel.in"};
  ofstream cout{"castel.out"};

  i64 c;
  cin >> c;

  i64 n;
  cin >> n;

  vv v(n, vi64(n));
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n; j++) {
      cin >> v[i][j];

      if (!m.count(v[i][j])) {
        i64 a = v[i][j];
        str s = "";
        while (a) {
          s += (a % 2) + '0';
          a /= 2;
        }

        while (s.size() < 4) {
          s += '0';
        }

        m[v[i][j]] = s;
      }
    }
  }

  vv rooms(n, vi64(n, -1));
  i64 crt = 0;
  p64 res = {-1e9, -1};
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n; j++) {
      if (rooms[i][j] == -1) {
        bfs(v, rooms, {i, j}, n, crt, res);
        crt++;
      }
    }
  }

  /*for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n; j++) {
      cout << rooms[i][j] << " ";
    }
    cout << endl;
  }*/

  if (c == 1) {
    cout << crt - 1 << endl;
  } else if (c == 2) {
    cout << res.first + 1 << endl;
  } else {
    p64 c1 = {-1, -1}, c2;
    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < n; j++) {
        if (rooms[i][j] == res.second) {
          if (c1.ft == -1 and c1.sd == -1) {
            c1 = {i, j};
          }
          c2 = {i, j};
        }
      }
    }

    cout << c1.ft + 1 << " " << c1.sd + 1 << " " << c2.ft + 1 << " "
         << c2.sd + 1 << endl;
  }

  return 0;
}