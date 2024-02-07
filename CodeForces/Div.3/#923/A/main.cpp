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

  i64 t;
  cin >> t;
  while (t--) {
    i64 n;
    cin >> n;

    i64 ft = -1, lt;
    for (i64 i = 0; i < n; i++) {
      char c;
      cin >> c;

      if (c == 'B') {
        if (ft == -1) {
          ft = i;
        }
        lt = i;
      }
    }

    cout << lt - ft + 1 << endl;
  }
  return 0;
}