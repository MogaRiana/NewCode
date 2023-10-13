#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;
  cin.ignore();

  while (n--) {
    vi64 v(26, 0);
    str s;
    getline(cin, s);

    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] >= 'a' and s[i] <= 'z') {
        v[s[i] - 'a']++;
      } else if (s[i] >= 'A' and s[i] <= 'Z') {
        v[s[i] - 'A']++;
      }
    }

    bool ok = false;
    for (i64 i = 0; i < v.size(); i++) {
      if (!ok and v[i] == 0) {
        cout << "missing " << char(i + 'a');
        ok = true;
      } else if (ok and v[i] == 0) {
        cout << char(i + 'a');
      }
    }

    if (!ok) {
      cout << "pangram";
    }

    cout << endl;
  }

  return 0;
}