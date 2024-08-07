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

/*
ID: Riana Moga (rianamo1)
TASK: wormhole
LANG: C++
*/

int n, x[12 + 1], y[12 + 1];
int part[12 + 1];
int next_right[12 + 1];

bool cycle() {
  for (int st = 1; st <= n; st++) {
    int pos = st;
    for (int c = 0; c < n; c++) {
      pos = next_right[part[pos]];
    }
    if (pos != 0) {
      return true;
    }
  }

  return false;
}

int solve() {
  int i, tot = 0;
  for (i = 1; i <= n; i++) {
    if (part[i] == 0) {
      break;
    }
  }

  if (i > n) {
    if (cycle()) {
      return 1;
    }
    return 0;
  }

  for (int j = i + 1; j <= n; j++) {
    if (part[j] == 0) {
      part[i] = j;
      part[j] = i;
      tot += solve();

      part[i] = part[j] = 0;
    }
  }

  return tot;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("wormhole.in");
  ofstream cout("wormhole.out");

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (x[i] < x[j] && y[j] == y[i]) {
        if (next_right[i] == 0 or x[j] - x[i] < x[next_right[i]] - x[i]) {
          next_right[i] = j;
        }
      }
    }
  }

  cout << solve() << endl;

  return 0;
}