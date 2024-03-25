#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long i64;
typedef vector<i64> vi64;
typedef pair<i64, i64> p64;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"opsir.in"};
  ofstream cout{"opsir.out"};

  int c, t;
  cin >> c >> t;

  if (c == 1) {
    while (t--) {
      int n, m;
      cin >> n >> m;

      unordered_map<char, int> s, t;
      set<char> cc;
      for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        s[c]++;
        cc.insert(c);
      }
      for (int i = 0; i < m; i++) {
        char c;
        cin >> c;

        t[c]++;
        cc.insert(c);
      }

      cout << cc.size() << endl;
      for (auto &x : cc) {
        if (s.count(x) and t.count(x)) {
          if (s[x] > t[x]) {
            cout << x << " S" << endl;
          } else {
            cout << x << " T" << endl;
          }
        } else if (!s.count(x) and t.count(x)) {
          cout << x << " T" << endl;
        } else if (s.count(x) and !t.count(x)) {
          cout << x << " S" << endl;
        }
      }
    }
  } else {
    while (t--) {
      int n, m;
      cin >> n >> m;

      str s, t;
      cin >> s >> t;

      if (s == t) {
        cout << "DA" << endl;
        continue;
      }

      if (!is_sorted(s.begin(), s.end())) {
        i64 k = 0;
        bool ok = true;
        for (i64 i = 0; i < m; i++) {
          if (t[i] != s[i - k]) {
            ok = true;
            for (i64 j = i + 1; j < m; j++) {
              if (t[j] == s[i - k]) {
                k += j - i;
                ok = true;
                break;
              } else {
                ok = false;
              }
            }

            if (!ok) {
              cout << "NU" << endl;
              break;
            }
          }
        }
        if (ok) {
          cout << "DA" << endl;
        }

        continue;
      }

      unordered_map<char, i64> ss, tt;
      for (i64 i = 0; i < n; i++) {
        ss[s[i]]++;
      }
      for (i64 i = 0; i < m; i++) {
        tt[t[i]]++;
      }

      if (tt.size() >= ss.size()) {
        bool ok = true;
        for (auto &x : ss) {
          auto c = x.first;
          if (tt.count(c)) {
            if (ss[c] > tt[c]) {
              ok = false;
              break;
            }
          } else {
            ok = false;
            break;
          }
        }

        if (ok) {
          cout << "DA" << endl;
        } else {
          cout << "NU" << endl;
        }
      } else {
        cout << "NU" << endl;
        continue;
      }
    }
  }

  return 0;
}
