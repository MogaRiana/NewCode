#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  set<i64> a;

  for (i64 i = 0; i < 10; i++) {
    i64 n;
    cin >> n;
    a.insert(n % 42);
  }

  cout << a.size() << endl;
}