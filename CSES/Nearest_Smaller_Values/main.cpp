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

  vi64 ans(n);
  vp64 st;
  for (i64 i = 0; i < n; i++) {
    if (st.empty()) {
      ans[i] = 0;
      st.push_back({v[i], i});
      continue;
    }

    bool found = false;
    while (!st.empty()) {
      if (st.back().first < v[i]) {
        ans[i] = st.back().second + 1;
        st.push_back({v[i], i});
        found = true;
        break;
      } else {
        st.pop_back();
      }
    }

    if (!found) {
      st.push_back({v[i], i});
      ans[i] = 0;
    }
  }

  for (auto &x : ans) {
    cout << x << " ";
  }

  return 0;
}