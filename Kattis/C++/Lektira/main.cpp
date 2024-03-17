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

void sol(i64 i, i64 j, str s, str &ans) {
  reverse(s.begin(), s.begin() + i);
  reverse(s.begin() + i, s.begin() + j);
  reverse(s.begin() + j, s.end());

  if (s < ans) {
    ans = s;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  cin >> s;

  str ans = "";
  for (i64 i = 0; i < 50; i++) {
    ans.push_back('z');
  }

  for (i64 i = 0; i < sz(s); i++) {
    for (i64 j = i + 2; j < sz(s); j++) {
      sol(i + 1, j, s, ans);
    }
  }

  cout << ans << endl;

  return 0;
}