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

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vi64 a(n), b(n);
    for (auto &i : a) {
      cin >> i;
    }
    for (auto &i : b) {
      cin >> i;
    }

    int cnt = 0;
    vp64 res;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        cnt++;
        res.push_back({3, i + 1});
        swap(a[i], b[i]);
      }
    }

    bool ok = true;
    while (ok) {
      ok = false;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
          cnt++;
          res.push_back({1, i + 1});
          swap(a[i], a[i + 1]);
          ok = true;
        }
      }
    }

    ok = true;
    while (ok) {
      ok = false;
      for (int i = 0; i < n - 1; i++) {
        if (b[i] > b[i + 1]) {
          cnt++;
          res.push_back({2, i + 1});
          swap(b[i], b[i + 1]);
          ok = true;
        }
      }
    }

    cout << cnt << endl;
    for (auto &x : res) {
      cout << x.ft << " " << x.sd << endl;
    }
  }

  return 0;
}