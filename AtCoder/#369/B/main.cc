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

  int n;
  cin >> n;

  int sl = 0, sr = 0;
  vi32 l, r;
  for (int i = 0; i < n; i++) {
    int a;
    char c;
    cin >> a >> c;

    if (c == 'L') {
      l.push_back(a);
    } else {
      r.push_back(a);
    }
  }

  for (int i = 1; i < sz(l); i++) {
    sl += abs(l[i] - l[i - 1]);
  }

  for (int i = 1; i < sz(r); i++) {
    sr += abs(r[i] - r[i - 1]);
  }

  cout << sl + sr << endl;

  return 0;
}