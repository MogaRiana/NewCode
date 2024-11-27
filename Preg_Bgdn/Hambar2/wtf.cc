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

i16 a[1000][1000];
int n, m;
i16 maxsz(vec<i16> &v) {
  i16 res = 0;
  i16 tp, cur;
  stack<i16> st;

  for (int i = 0; i < v.size(); i++) {
    while (!st.empty() and v[st.top()] > v[i]) {
      tp = st.top();
      st.pop();
      i16 w = st.empty() ? i : i - st.top() - 1;
      i16 h = v[tp];
      res = max(res, i16(w * h));
    }
    st.push(i);
  }

  while (!st.empty()) {
    tp = st.top();
    st.pop();
    cur = v[tp] * (st.empty() ? n : n - st.top() - 1);
    res = max(res, cur);
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"hambar2.in"};
  ofstream cout{"hambar2.out"};

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    i16 x, y;
    cin >> x >> y;
    x--;
    y--;
    a[x][y] = 1;
  }

  i16 ans = 0;
  vec<i16> v(m + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        v[j]++;
      } else {
        v[j] = 0;
      }
    }
    ans = max(ans, maxsz(v));
  }

  cout << ans << endl;

  return 0;
}