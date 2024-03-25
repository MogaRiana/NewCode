#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef int i32;
typedef long long i64;
typedef vector<i32> vi32;
typedef vector<i64> vi64;
typedef vector<vi32> vv;
typedef pair<i32, i32> p32;

const vi32 dirx = {1, -1, 0, 0};
const vi32 diry = {0, 0, 1, -1};

unordered_map<i64, i64> dp;

i64 derang(i64 n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return 0;
  }

  if (dp.count(n)) {
    return dp[n];
  }

  return dp[n] = derang(n - 1) * (derang(n - 1) + derang(n - 2));
}

bool ver(int x, int y, p32 cor) {
  int l = cor.first, c = cor.second;
  if (x >= 0 and x < l and y >= 0 and y < c) {
    return true;
  }
  return false;
}

int bfs(vv &v, p32 cor, p32 st, vector<vector<bool>> &visit) {
  int crt = 0;
  int l = cor.first, c = cor.second;

  queue<p32> q;
  q.push(st);
  visit[st.first][st.second] = true;

  while (!q.empty()) {
    p32 cur = q.front();
    q.pop();
    int x = cur.first, y = cur.second;
    if (v[x][y] != 0 and !visit[x][y]) {
      crt++;
    }
    visit[x][y] = true;

    for (int k = 0; k < 4; k++) {
      int xx = x + dirx[k];
      int yy = y + diry[k];

      if (ver(xx, yy, cor) and v[xx][yy] != -1 and !visit[xx][yy]) {
        q.push({xx, yy});
      }
    }
  }

  return crt;
}

i64 MOD = 1e9 + 7;

i64 mult(i64 x, i64 y) { return (x * y) % MOD; }
i64 mod(i64 n) { return (n < MOD) ? n : n % MOD; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"poseidon.in"};
  ofstream cout{"poseidon.out"};

  int c;
  cin >> c;

  int n, m;
  p32 st = {0, 0};
  cin >> n >> m;

  vv v(n, vi32(m));
  vector<vector<bool>> visit(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  if (c == 1) {
    cin >> st.first >> st.second;
    st.first--;
    st.second--;
    cout << bfs(v, {n, m}, st, visit) << endl;
  } else {
    i64 res = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] != -1 and !visit[i][j]) {
          int nc = bfs(v, {n, m}, {i, j}, visit);

          res *= derang(n);
        }
      }
    }
    cout << res << endl;
  }

  return 0;
}
