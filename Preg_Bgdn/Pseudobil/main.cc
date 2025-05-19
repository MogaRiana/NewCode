#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i32) x.size()
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
typedef pair<i32, i32> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

const i32 NMAX = 1505;
i32 n, k, d;
i32 pref[2 * NMAX][2 * NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"pseudobil.in"};
  ofstream cout{"pseudobil.out"};

  i16 cer;
  cin >> cer;

  cin >> n >> k >> d;

  for (int i = 0; i < k; i++) {
    i32 x, y;
    cin >> x >> y;
    pref[x + y - 1][n - x + y] = 1;
  }

  for (i32 i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
      // cout << pref[i][j] << " ";
    }
    // cout << endl;
  }

  if (cer == 1) {
    cout << d * (d / 2) - (d - 1) << endl;
  }

  i32 q;
  cin >> q;
  while (q--) {
    i32 x, y;
    cin >> x >> y;

    i32 xx = x + d / 2;
    i32 yy = y + d / 2;
    // cout << xx << " " << yy << endl;
    p64 E = {xx + yy - 1, n - xx + yy};

    x = x + d / 2;
    yy = y - d / 2;
    p64 V = {xx + yy - 1, n - xx + yy};
    // cout << E.ft << " " << E.sd << endl;

    if (cer == 2) {
      cout << pref[E.ft][E.sd] - pref[V.ft - 1][E.sd] - pref[E.ft][V.sd - 1] +
                  pref[V.ft - 1][V.sd - 1]
           << endl;
    }
  }

  return 0;
}