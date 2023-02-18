#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<v> vv;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  char a, b;
  i64 sum = 0;
  while (cin >> a >> b) {
    if (a == 'A' && b == 'X') {
      sum += 3 + 0;
    } else if (a == 'A' && b == 'Y') {
      sum += 1 + 3;
    } else if (a == 'A' && b == 'Z') {
      sum += 2 + 6;
    } else if (a == 'B' && b == 'X') {
      sum += 1 + 0;
    } else if (a == 'B' && b == 'Y') {
      sum += 2 + 3;
    } else if (a == 'B' && b == 'Z') {
      sum += 3 + 6;
    } else if (a == 'C' && b == 'X') {
      sum += 2 + 0;
    } else if (a == 'C' && b == 'Y') {
      sum += 3 + 3;
    } else if (a == 'C' && b == 'Z') {
      sum += 1 + 6;
    }
  }
  cout << sum << endl;
  return 0;
}
