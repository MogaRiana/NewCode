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

  i64 n;
  cin >> n;

  vp64 v(n), v2(n);
  map<i64, i64> f;
  for (i64 i = 0; i < n; i++) {
    cin >> v[i].ft;
    v2[i].sd = v[i].ft;
    f[v[i].ft]++;
  }
  for (i64 i = 0; i < n; i++) {
    cin >> v[i].sd;
    v2[i].ft = v[i].sd;
  }

  srt(v);
  srt(v2);
  vi64 s(n, 0);
  s[0] = v[0].sd;

  for (i64 i = 1; i < n; i++) {
    s[i] = s[i - 1] + v[i].sd;
  }

  i64 res = 1e18;
  for (auto &i : f) {
    i64 a = i.ft;

    i64 pos = -1;
    i64 l = 0, r = n - 1;
    while (l <= r) {
      i64 mid = l + (r - l) / 2;
      if (v[mid].ft <= a) {
        l = mid + 1;
        pos = mid;
      } else {
        r = mid - 1;
      }
    }

    i64 sum = s[n - 1] - s[pos];
    i64 j = 0, crt = n - 1 - pos, el = n - 2 * i.sd + 1;
    while (crt < el and j < pos) {
      if (v2[j].sd < i.ft) {
        sum += v2[j].ft;
        crt++;
      }
      j++;
    }

    res = min(sum, res);
  }

  cout << res << endl;

  return 0;
}