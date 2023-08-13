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

  i64 crt = 0;

  for (i64 i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0 and i * i <= n) {
        crt++;
        n /= i;
      }
    }
  }

  cout << crt + 1 << endl;

  return 0;
}
