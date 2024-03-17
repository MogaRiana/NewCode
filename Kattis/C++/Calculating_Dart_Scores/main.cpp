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

str an(i64 x) {
  if (x % 3 == 0) {
    return "single ";
  } else if (x % 3 == 1) {
    return "double ";
  } else {
    return "triple ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int s;
  cin >> s;

  vi64 v = {1,  2,  3,  2,  4,  6,  3,  6,  9,  4,  8,  12, 5,  10, 15,
            6,  12, 18, 7,  14, 21, 8,  16, 24, 9,  18, 27, 10, 20, 30,
            11, 22, 33, 12, 24, 36, 13, 26, 39, 14, 28, 42, 15, 30, 45,
            16, 32, 48, 17, 34, 51, 18, 36, 54, 19, 38, 57, 20, 40, 60};

  for (int i = 0; i < 60; i++) {
    if (v[i] == s) {
      cout << an(i) << i / 3 + 1 << endl;
      return 0;
    }

    for (int j = 0; j < 60; j++) {
      if (v[i] + v[j] == s) {
        cout << an(i % 3) << i / 3 + 1 << endl;
        cout << an(j % 3) << j / 3 + 1 << endl;
        return 0;
      }

      for (int k = 0; k < 60; k++) {
        if (v[i] + v[j] + v[k] == s) {
          cout << an(i % 3) << i / 3 + 1 << endl;
          cout << an(j % 3) << j / 3 + 1 << endl;
          cout << an(k % 3) << k / 3 + 1 << endl;
          return 0;
        }
      }
    }
  }
  cout << "impossible" << endl;

  return 0;
}
