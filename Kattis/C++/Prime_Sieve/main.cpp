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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 nn, q, crt = 0;
  cin >> nn >> q;

  vector<bool> prime(nn, true);
  for (i64 i = 2; i <= nn; i++) {
    if (prime[i]) {
      crt++;
      for (i64 k = i * i; k <= nn; k += i) {
        prime[k] = false;
      }
    }
  }

  cout << crt << endl;
  while (q--) {
    i64 x;
    cin >> x;

    if (prime[x] and x != 1) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}