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

void ver(str s1, str s2, vec<bool> &v) {
  if (s1[0] == s2[0]) {
    v[0] = true;
  }
  if (s1[1] == s2[1]) {
    v[1] = true;
  }
  if (s1[2] == s2[2]) {
    v[2] = true;
  }
  if (s1[3] == s2[3]) {
    v[3] = true;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vec<str> v(12);
  for (int i = 0; i < 12; i++) {
    cin >> v[i];
  }

  vv res;
  for (i64 i = 0; i < 12; i++) {
    for (i64 j = i + 1; j < 12; j++) {
      vec<bool> aa(4, false);
      ver(v[i], v[j], aa);

      for (i64 k = j + 1; k < 12; k++) {
        vec<bool> bb(4, false);
        ver(v[j], v[k], bb);

        vec<bool> cc(4, false);
        ver(v[i], v[k], cc);

        bool ok = true;
        for (i64 ch = 0; ch < 4; ch++) {
          if (aa[ch] != bb[ch] or aa[ch] != cc[ch] or bb[ch] != cc[ch]) {
            ok = false;
          }
        }

        if (ok) {
          res.push_back({i + 1, j + 1, k + 1});
        }
      }
    }
  }

  if (res.empty()) {
    cout << "no sets" << endl;
  } else {
    for (i64 i = 0; i < res.size(); i++) {
      for (i64 j = 0; j < 3; j++) {
        cout << res[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}