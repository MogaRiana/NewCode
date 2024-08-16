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
    str n;
    cin >> n;

    if (n[0] != '1' or sz(n) <= 2 or n[1] != '0') {
      cout << "no" << endl;
      continue;
    }

    i64 k = n[2] - '0';
    if (k == 0) {
      cout << "no" << endl;
      continue;
    }

    for (i64 i = 3; i < sz(n); i++) {
      k = k * 10 + n[i] - '0';
    }

    if (k > 1) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}