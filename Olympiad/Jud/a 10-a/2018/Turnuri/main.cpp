#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i6) x.size()
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

  ifstream cin{"turnuri.in"};
  ofstream cout{"turnuri.out"};

  i64 n;
  cin >> n;

  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (i64 i = 0; i < n; i++) {
    i64 tot = 0;
    i64 an = v[i];
    v[i] = 0;

    for (i64 k = 0; k < n; k++) {
      i64 tt = 1;
      for (i64 j = k - 1; j >= 0; j--) {
        if (v[j] < v[k]) {
          tt++;
        } else {
          break;
        }
      }
      for (i64 j = k + 1; j < n; j++) {
        if (v[j] < v[k]) {
          tt++;
        } else {
          break;
        }
      }

      tot += tt;
    }

    v[i] = an;
    cout << tot << endl;
  }

  return 0;
}