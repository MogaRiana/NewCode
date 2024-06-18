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

    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    vector<str> s;
    for (i64 i = 0; i < n - 2; i++) {
      str temp;
      for (i64 j = i; j < i + 3; j++) {
        temp += char(v[j]);
      }

      s.push_back(temp);
    }

    i64 crt = 0;
    for (i64 i = 0; i < sz(s); i++) {
      for (i64 j = i + 1; j < sz(s); j++) {
        i64 c = 0;
        for (i64 k1 = 0; k1 < 3; k1++) {
          if (s[i][k1] != s[j][k1]) {
            c++;
          }
        }

        if (c == 1) {
          crt++;
        }
      }
    }
    cout << crt << endl;
  }
  return 0;
}