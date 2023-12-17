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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    str s;
    cin >> s;

    vector<pair<char, i64>> v;
    vi64 low, upper;

    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] != 'b' and s[i] != 'B') {
        v.push_back({s[i], 1});
        if (s[i] >= 'a' and s[i] <= 'z') {
          low.push_back(v.size() - 1);
        } else if (s[i] >= 'A' and s[i] <= 'Z') {
          upper.push_back(v.size() - 1);
        }
      } else if (s[i] == 'b' and !low.empty()) {
        v[low.back()].second = 0;
        low.pop_back();
      } else if (s[i] == 'B' and !upper.empty()) {
        v[upper.back()].second = 0;
        upper.pop_back();
      }
    }

    for (i64 i = 0; i < v.size(); i++) {
      if (v[i].second) {
        cout << v[i].first;
      }
    }

    cout << endl;
  }

  return 0;
}
