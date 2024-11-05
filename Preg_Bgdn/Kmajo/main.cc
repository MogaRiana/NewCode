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

i64 f[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin{"kmajo.in"};
  // ofstream cout{"kmajo.out"};

  i64 n, k;
  cin >> n >> k;

  vi64 a(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> a[i];
  }

  set<i64> res;
  i64 j = 1, i = 1;
  i64 maxf = a[1];
  for (i = 1; i <= n - k + 1; i++) {
    maxf = a[i];
    while (j <= n) {
      f[a[j]]++;
      if (f[a[j]] > f[maxf]) {
        maxf = a[j];
      }

      j++;
    }

    if (j - i + 1 >= k) {
      if (f[maxf] > (j - i) / 2 + 1) {
        res.insert(maxf);
      }
    }

    f[a[i]]--;
  }

  if (sz(res) == 0) {
    cout << -1;
    return 0;
  }

  for (auto &x : res) {
    cout << x << " ";
  }

  cout << endl;

  return 0;
}