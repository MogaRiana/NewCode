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
    i64 n, k;
    cin >> n >> k;

    str s;
    cin >> s;

    i64 crt = 0;
    i64 ones = 0, zeros = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == s[n - i - 1]) {
        crt++;
      }
      if (s[i] == '1') {
        ones++;
      }
    }

    zeros = n - ones;

    cout << crt << endl;
    if (crt == k) {
      cout << "YES" << endl;
      continue;
    }
    if ((ones == n or zeros == n) and crt != k) {
      cout << "NO" << endl;
      continue;
    }
  }

  return 0;
}