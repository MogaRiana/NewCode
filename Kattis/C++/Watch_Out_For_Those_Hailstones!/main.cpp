#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 s = 0;

void h(i64 n) {
  s += n;

  if (n == 1) {
    return;
  } else if (n % 2 == 0) {
    return h(n / 2);
  } else {
    return h(3 * n + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;
  h(n);
  cout << s << endl;

  return 0;
}
