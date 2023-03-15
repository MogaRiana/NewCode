#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    gcd(b, a % b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout << gcd(4, 7) << endl;
  return 0;
}