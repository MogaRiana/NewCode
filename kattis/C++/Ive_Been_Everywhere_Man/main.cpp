#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i64 n;
  cin >> n;

  while (n--) {
    map<string, i64> m;
    i64 a;
    cin >> a;

    while (a--) {
      string t;
      cin >> t;
      m[t]++;
    }

    cout << m.size() << endl;
  }

  return 0;
}