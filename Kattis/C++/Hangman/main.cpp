#include <bits/stdc++.h>
#include <cstddef>

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

  str cuv, g;
  cin >> cuv >> g;

  map<char, i64> m;
  for (i64 i = 0; i < cuv.size(); i++) {
    m[cuv[i]] = 1;
  }

  i64 crt = 0, crtw = 0;
  for (i64 i = 0; i < g.size() and crt < 10 and crtw < m.size(); i++) {
    if (m.find(g[i]) == m.end()) {
      crt++;
    } else {
      crtw++;
    }
  }

  if (crtw == m.size() and crt <= 10) {
    cout << "WIN" << endl;
  } else {
    cout << "LOSE" << endl;
  }

  return 0;
}