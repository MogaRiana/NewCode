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

const int NMAX = 100002;
const int MOD = 20011;
int f[NMAX], pref[NMAX];
int n, k;

int bs(int a, vi64 &m) {
  int l = 0, r = m.size() - 1, res = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (m[mid] < a) {
      r = mid - 1;
      res = mid;
    } else {
      l = mid + 1;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"calcule.in"};
  ofstream cout{"calcule.out"};

  cin >> n >> k;

  vi64 m(0);
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  f[0]++;
  pref[0] = v[0];
  f[pref[0] % k]++;
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + v[i];
    f[pref[i] % k]++;
  }

  m.push_back(v[0]);
  for (int i = 1; i < n; i++) {
    int x = bs(v[i], m);

    if (x == -1) {
      m.push_back(v[i]);
    } else {
      m[x] = v[i];
    }
  }

  cout << m.size() << endl;

  int crt = 0;
  for (int i = 0; i < k; i++) {
    crt = (crt + (f[i] * (f[i] - 1)) / 2) % MOD;
  }

  cout << crt << endl;

  return 0;
}