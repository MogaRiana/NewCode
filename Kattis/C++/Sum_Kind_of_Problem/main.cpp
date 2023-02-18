#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  i64 k;
  cin >> k;
  for (i64 i = 0; i < k; i++) {
    i64 a, n;
    cin >> a >> n;
    i64 s1 = (1 + n) * n / 2, s2, s3;

    s3 = 2 * s1;
    s2 = s3 - n;

    cout << a << " " << s1 << " " << s2 << " " << s3 << endl;
  }

  return 0;
}