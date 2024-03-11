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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"parcare.in"};
  ofstream cout{"parcare.out"};

  i64 n, m, t;
  cin >> n >> m >> t;

  vi64 v(n + 1, -1);

  map<i64, p64> in;
  for (i64 i = 1; i <= m; i++) {
    i64 l, r;
    cin >> l >> r;

    in[l] = {1, r};
    in[r] = {0, l};
  }

  auto it = in.begin();

  while (it != in.end()) {
    if (it->ft > t) {
      break;
    }
    if (it->sd.ft) {
      bool ok = false;
      for (i64 i = 1; i <= n; i++) {
        if (v[i] == -1) {
          v[i] = it->ft;
          ok = true;
          cout << i << endl;
          break;
        }
      }

      if (!ok) {
        cout << -1 << endl;
      }
    } else {
      for (i64 i = 1; i <= n; i++) {
        if (v[i] == it->sd.sd) {
          v[i] = -1;
          break;
        }
      }
    }

    it++;
  }

  for (i64 i = 1; i <= n; i++) {
    cout << v[i] << " ";
  }

  return 0;
}