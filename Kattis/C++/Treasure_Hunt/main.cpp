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
i64 m = 0;
string mt[200];
string sol = "lost";
bool vis[200][200];

void solve(i64 x, i64 y) {
  if (x < 0 || x >= l || y < 0 || y >= c) {
    sol = "Out";
    return;
  }
  if (mt[x][y] == 'T') {
    sol = "Won";
    return;
  }
  if (vis[x][y]) {
    sol = "Lost";
    return;
  }

  vis[x][y] = true;
  switch (mt[x][y]) {
  case 'N':
    x -= 1;
    break;
  case 'S':
    x += 1;
    break;
  case 'E':
    y += 1;
    break;
  case 'W':
    y -= 1;
    break;
  }
  m += 1;
  solve(x, y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> l >> c;
  for (i64 i = 0; i < l; i++) {
    cin >> mt[i];
  }

  solve(0, 0);

  if (sol == "Won") {
    cout << m;
  } else {
    cout << sol;
  }

  return 0;
}