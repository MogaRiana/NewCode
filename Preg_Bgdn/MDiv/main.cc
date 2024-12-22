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

const i64 NM = 1e6 + 2;
i64 f[NM], r[NM];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"mdiv.in"};
  ofstream cout{"mdiv.out"};

  i64 n, mm = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    mm = max(mm, x);
    f[x]++;
  }

  int m;
  cin >> m;
  while (m--) {
    int k;
    cin >> k;

    if (r[k] == 0) {
      if (k != 1) {
        for (int i = 0; i <= mm; i += k) {
          r[k] += f[i];
        }
      } else {
        r[k] = n;
      }
    }

    cout << r[k] << endl;
  }

  return 0;
}