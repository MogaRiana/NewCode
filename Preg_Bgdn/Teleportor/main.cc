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

int n, k;
int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};

int f[1000 * 1000 + 1];

bool ver(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < n); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"teleportor.in"};
  ofstream cout{"teleportor.out"};

  cin >> n >> k;

  int mat[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int kk = 0; kk < 4; kk++) {
        int x = i + dirx[kk];
        int y = j + diry[kk];

        if (ver(x, y) and mat[i][j] + 1 == mat[x][y]) {
          f[mat[i][j]]++;
        }
      }
    }
  }

  for (int i = 1; i <= k; i++) {
    if (f[i]) {
      cnt++;
    }
  }

  cout << k - cnt - 1 << endl;

  int q;
  cin >> q;

  while (q--) {
    int ii, jj, c;
    cin >> ii >> jj >> c;

    ii--;
    jj--;

    int tmp = mat[ii][jj];
    mat[ii][jj] = c;

    bool oka = false, okb = false;
    if (f[c] == 0) {
      oka = true;
    }
    if (f[c - 1] == 0) {
      okb = true;
    }

    for (int kk = 0; kk < 4; kk++) {
      int x = ii + dirx[kk];
      int y = jj + diry[kk];

      if (ver(x, y) and mat[ii][jj] + 1 == mat[x][y]) {
        f[mat[ii][jj]]++;
      }
      if (ver(x, y) and mat[ii][jj] == mat[x][y] + 1) {
        f[mat[x][y]]++;
      }
      if (ver(x, y) and tmp + 1 == mat[x][y]) {
        f[tmp]--;
        if (f[tmp] <= 0) {
          cnt--;
          f[tmp] = 0;
        }
      }
      if (ver(x, y) and tmp == mat[x][y] + 1) {
        f[mat[x][y]]--;
        if (f[mat[x][y]] <= 0) {
          cnt--;
          f[mat[x][y]] = 0;
        }
      }
    }

    if (oka) {
      if (f[c] != 0) {
        cnt++;
      }
    }
    if (okb) {
      if (f[c - 1] != 0) {
        cnt++;
      }
    }

    cout << k - cnt - 1 << endl;
  }

  return 0;
}