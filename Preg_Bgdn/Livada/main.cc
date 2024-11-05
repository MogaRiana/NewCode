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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"livada.in"};
  ofstream cout{"livada.out"};

  i64 m, n, p;
  cin >> m >> n >> p;

  i64 nrp = 0, nrm = 0;
  while (m--) {
    i64 crt = 1, nr = -1;
    vi64 t(n);

    cin >> nr;
    t[0] = nr;
    for (i64 i = 1; i < n; i++) {
      cin >> t[i];
      if (t[i] == nr) {
        crt++;
      } else {
        nrp = max(crt, nrp);
        nr = t[i];
        crt = 1;
      }
    }

    i64 x = t[0];
    i64 sc = 1;

    for (i64 i = 1; i < n; i++) {
      if (t[i] == x) {
        sc++;
      } else {
        sc--;
      }

      if (sc == 0) {
        x = t[i];
        sc = 1;
      }
    }

    sc = 0;
    for (i64 i = 0; i < n; i++) {
      if (t[i] == x) {
        sc++;
      }
    }

    if (sc >= (n / 2) + 1) {
      nrm++;
    }
  }

  cout << nrm << endl;
  cout << nrp << endl;

  return 0;
}