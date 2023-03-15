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
  ifstream cin{"balba.in"};
  ofstream cout{"balba.out"};

  i32 p;
  cin >> p;

  if (p == 1) {
    i32 n;
    cin >> n;
    map<i32, i32> res;

    i32 a;
    cin >> a;
    for (i32 i = 0; i < n - 1; i++) {
      i32 b = a;
      cin >> a;
      if (a == b) {
        res[a]++;
      }
    }

    if (res.size() == 0) {
      cout << n << endl << 0 << endl;
    } else {

      i32 crt = n;
      for (auto x : res) {
        crt -= x.second + 1;
      }
      cout << n - crt << endl << res.size() << endl;
    }
  } else {
    i32 n;
    cin >> n;
    map<i32, i32> res;
    vi64 v(n);
    for (i32 i = 0; i < n; i++) {
      cin >> v[i];
      res[v[i]]++;
    }

    sort(v.rbegin(), v.rend());
    i32 im, impar = -1, par = -1, impap = -1, a = impap;
    for (auto x : res) {
      impap = max(impap, x.second);
      if (impap != a) {
        im = x.first;
      }

      res[x.first] = x.second % 2;
      if (x.second == 1) {
        impar = x.first;
      } else {
        par = x.first;
      }
    }

    i64 nr;
    if (impar == -1) {
      nr = v[0];
      for (i32 i = 2; i < n; i += 2) {
        nr = nr * 10 + v[i];
      }
      for (i32 i = n - 2; i > 0; i -= 2) {
        nr = nr * 10 + v[i];
      }

    } else if (impar != -1 && par != -1) {
      if (res[v[0]] == 0) {
        nr = v[0];
        for (i32 i = 2; i < n; i += 2) {
          nr = nr * 10 + v[i];
        }
        for (i32 i = n - 2; i > 0; i -= 2) {
          if (res[v[i]] == 1) {
            if (v[i] == v[i - 1]) {
              nr = nr * 10 + v[i];
            }
          } else {
            nr = nr * 10 + v[i];
          }
        }
      } else {
        i32 pos;
        bool ok = true;
        for (i64 i = 1; i < v.size(); i++) {
          if (res[v[i]] == 0 && ok) {
            nr = v[i];
            ok = false;
            pos = i;
          } else if (v[i] == nr) {
            pos = i;
          }
        }

        for (i32 i = pos + 1; i < n; i += 2) {
          nr = nr * 10 + v[i];
        }
        nr = nr * 10 + v[0];
        for (i32 i = n - 2; i > 0; i -= 2) {
          if (res[v[i]] == 1) {
            if (v[i] == v[i - 1]) {
              nr = nr * 10 + v[i];
            }
          } else {
            nr = nr * 10 + v[i];
          }
        }
      }
    }

    cout << nr;
  }

  return 0;
}