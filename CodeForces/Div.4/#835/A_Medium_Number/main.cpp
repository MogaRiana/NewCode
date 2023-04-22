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

  i64 t;
  cin >> t;

  while (t--) {
    vi64 v(3);
    for (i64 i = 0; i < 3; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    cout << v[1] << endl;
  }

  return 0;
}