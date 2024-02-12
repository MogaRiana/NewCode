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

  i64 n;
  str s;

  cin >> n;
  cin.ignore();
  getline(cin, s);

  deque<char> ress;
  for (i64 i = 0; i < n; i++) {
    if (s[i] == '[' or s[i] == '{' or s[i] == '(') {
      ress.push_back(s[i]);
    } else if (s[i] == ']' or s[i] == '}' or s[i] == ')') {
      if (!ress.empty()) {
        if (ress.back() == s[i] - 1 or ress.back() == s[i] - 2) {
          ress.pop_back();
        } else if (ress.back() != s[i] - 1 and ress.back() != s[i] - 2) {
          cout << s[i] << " " << i << endl;
          return 0;
        }
      } else {
        cout << s[i] << " " << i << endl;
        return 0;
      }
    }
  }

  cout << "ok so far" << endl;

  return 0;
}