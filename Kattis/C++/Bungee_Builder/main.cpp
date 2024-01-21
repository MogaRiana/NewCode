#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;

i64 solve(stack<p64> &st, i64 val) {
  if (st.empty()) {
    st.push({val, val});
    return 0;
  }

  bool found = false;
  i64 res = 0;
  while (!st.empty()) {
    if (st.top().first >= val) {
      st.top().second = min(val, st.top().second);
      st.push({val, min(val, st.top().second)});
      res = max(val - st.top().second, res);
      found = true;
      break;
    } else {
      i64 last = st.top().second;
      st.pop();

      if (!st.empty()) {
        st.top().second = min(last, st.top().second);
      }
    }
  }

  if (!found) {
    st.push({val, val});
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  vi64 v(n);
  for (auto &x : v) {
    cin >> x;
  }

  i64 res = 0;
  stack<p64> st1;
  for (i64 i = 0; i < n; i++) {
    res = max(res, solve(st1, v[i]));
  }

  stack<p64> st2;
  for (i64 i = n - 1; i >= 0; i--) {
    res = max(res, solve(st2, v[i]));
  }

  cout << res << endl;

  return 0;
}