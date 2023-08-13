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

  i64 n, p, a = 2;
  cin >> n >> p;

  if (p == 1) {
    cout << a << endl;
    return 0;
  }

  vector<bool> prime(n + 1, true);
  for (i64 i = 2, j = 1; i <= n and j <= p; i++) {
    if (prime[i]) {
      j++;
      a = i;
      for (i64 k = i * i; k <= n and j <= p; k += i) {
        if (prime[k]) {
          prime[k] = false;
          a = k;
          j++;
        }
      }
    }
  }

  cout << a << endl;

  return 0;
}