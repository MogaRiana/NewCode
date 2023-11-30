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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int *a = new int[3];
  a[0] = 1;
  a[1] = 89;
  a[2] = 10;

  cout << a << endl;

  int *b = a + 20222022;
  cout << b << " " << (*b) << endl;

  return 0;
}
