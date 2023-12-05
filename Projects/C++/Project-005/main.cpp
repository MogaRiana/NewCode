#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef string str;

int main() {
  str s = "BAAC";
  cout << s << endl;

  while (next_permutation(s.begin(), s.end())) {
    cout << s << endl;
  }

  return 0;
}