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

  ifstream cin{"trompeta.in"};
  ofstream cout{"trompeta.out"};

  int n, m;
  cin >> n >> m;

  str s;
  cin >> s;

  int cnt = 0;
  vec<char> st;
  for (auto &c : s) {
    while (!st.empty() and st.back() < c and cnt < n - m) {
      cnt++;
      st.pop_back();
    }
    st.push_back(c);
  }

  while (cnt < n - m) {
    cnt++;
    st.pop_back();
  }

  for (auto &c : st) {
    cout << c;
  }

  return 0;
}