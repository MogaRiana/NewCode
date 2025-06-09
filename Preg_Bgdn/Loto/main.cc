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

  ifstream cin{"loto.in"};
  ofstream cout{"loto.out"};

  int n, t;
  cin >> n >> t;

  vi32 v(n);
  for (auto &i : v) {
    cin >> i;
  }

  vec<pair<int, vec<int>>> s;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        int p = v[i] + v[j] + v[k];
        if (p < t) {
          s.push_back({p, {i, j, k}});
        }
      }
    }
  }

  srt(s);
  int l = 0, r = sz(s) - 1;
  while (l <= r) {
    int sl = s[l].ft;
    int sr = s[r].ft;

    if (sl + sr == t) {
      for (int i = 0; i < 3; i++) {
        cout << v[s[l].sd[i]] << " ";
      }
      for (int i = 0; i < 3; i++) {
        cout << v[s[r].sd[i]] << " ";
      }
      return 0;
    } else if (sl + sr < t) {
      l++;
    } else {
      r--;
    }
  }

  cout << -1 << endl;

  return 0;
}