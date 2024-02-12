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
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 q;
  cin >> q;

  while (q--) {
    str s;
    i64 n;

    cin >> s >> n;

    str list;
    cin >> list;
    deque<i64> d;
    i64 nr = -1;
    for (i64 i = 1; i < list.size(); i++) {
      if (list[i] == ',') {
        d.push_back(nr);
        nr = -1;
      } else if (list[i] >= '0' && list[i] <= '9') {
        if (nr == -1) {
          nr = list[i] - '0';
        } else {
          nr = nr * 10 + list[i] - '0';
        }
      }
    }

    if (nr != -1) {
      d.push_back(nr);
    }

    bool rev = false, ok = true;
    for (auto &c : s) {
      if (c == 'R') {
        rev = !rev;
      } else if (c == 'D') {
        if (!d.empty()) {
          if (rev) {
            d.pop_back();
          } else if (!rev) {
            d.pop_front();
          }
        } else {
          cout << "error" << endl;
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      cout << "[";
      if (rev) {
        for (i64 i = d.size() - 1; i >= 0; i--) {
          if (i != 0) {
            cout << d[i] << ",";
          } else if (i == 0) {
            cout << d[i];
          }
        }
      } else {
        for (i64 i = 0; i < d.size(); i++) {
          if (i != d.size() - 1) {
            cout << d[i] << ",";
          } else if (i == d.size() - 1) {
            cout << d[i];
          }
        }
      }
      cout << "]" << endl;
    }
  }

  return 0;
}