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
  cin.ignore();

  while (n--) {
    str s;
    getline(cin, s);
    deque<char> d;
    deque<char> ss;
    bool pushb = true;

    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] == '<') {
        if (pushb == true) {
          if (!d.empty()) {
            d.pop_back();
          }
        } else {
          if (!ss.empty()) {
            ss.pop_back();
          }
        }
      } else if (s[i] == ']') {
        pushb = true;
      } else if (s[i] == '[') {
        pushb = false;
        while (!ss.empty()) {
          d.push_front(ss.back());
          ss.pop_back();
        }

        ss.clear();
      } else {
        if (pushb) {
          d.push_back(s[i]);
        } else {
          ss.push_back(s[i]);
        }
      }
    }
    while (!ss.empty()) {
      d.push_front(ss.back());
      ss.pop_back();
    }

    for (i64 i = 0; i < d.size(); i++) {
      cout << d[i];
    }
    cout << endl;
  }

  return 0;
}
