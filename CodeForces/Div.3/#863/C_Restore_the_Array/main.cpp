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
    i64 n;
    cin >> n;
    vi64 b(n - 1);

    for (i64 i = 0; i < n - 1; i++) {
      cin >> b[i];
    }

    cout << b[0] << " ";
    for (i64 i = 1; i < n - 1; i++) {
      cout << min(b[i], b[i - 1]) << " ";
    }
    cout << b[n - 2] << endl;
  }

  return 0;
}