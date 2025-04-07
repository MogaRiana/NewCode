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

vec<bool> vis;
vi64 v;
vv g;
vi64 sum;
vp64 m;

int crt = 0;

void cycle(int i) {
  if (vis[i]) {
    crt++;
    return;
  }

  vis[i] = true;

  if (g.size() == crt) {
    g.push_back({v[i]});
    sum.push_back(0);
  } else {
    g[crt].push_back(v[i] + g[crt].back());
  }

  m[i] = {crt, g[crt].size() - 1};
  sum[crt] += v[i];

  cycle(v[i]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"investitie.in"};
  ofstream cout{"investitie.out"};

  int N, M;
  cin >> N >> M;

  v.resize(N + 1);
  vis.assign(N + 1, false);
  m.assign(N + 1, {0, 0});

  for (int i = 1; i <= N; i++) {
    cin >> v[i];
  }

  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      cycle(i);
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int z1, z2, c1, c2;
    cin >> z1 >> z2 >> c1 >> c2;

    int z = z2 - z1 + 1;
    i64 res = 0;

    for (int i = c1; i <= c2; i++) {
      res += sum[m[i].ft] * (z / g[m[i].ft].size());
      int tmp = z % g[m[i].ft].size();

      if (tmp != 0) {
        int aux = (m[i].second + z1 - 1) % g[m[i].first].size();
        if (aux + tmp - 1 < g[m[i].first].size()) {
          res += g[m[i].first][aux + tmp - 1];
          if (aux != 0) {
            res -= g[m[i].first][aux - 1];
          }
        } else {
          res += g[m[i].first].back() - g[m[i].first][aux - 1];
          tmp -= g[m[i].first].size() - aux;
          res += g[m[i].first][tmp - 1];
        }
      }
    }
    cout << res << endl;
  }

  return 0;
}