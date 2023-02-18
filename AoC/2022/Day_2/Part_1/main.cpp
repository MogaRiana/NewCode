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
    if (b == 'X') {
      sum += 1;
    } else if (b == 'Y') {
      sum += 2;
    } else if (b == 'Z') {
      sum += 3;
    }
    if (a == 'A' && b == 'X') {
      sum += 3;
    } else if (a == 'A' && b == 'Z') {
      sum += 0;
    } else if (a == 'A' && b == 'Y') {
      sum += 6;
    } else if (a == 'B' && b == 'Y') {
      sum += 3;
    } else if (a == 'B' && b == 'X') {
      sum += 0;
    } else if (a == 'B' && b == 'Z') {
      sum += 6;
    } else if (a == 'C' && b == 'Z') {
      sum += 3;
    } else if (a == 'C' && b == 'Y') {
      sum += 0;
    } else if (a == 'C' && b == 'X') {
      sum += 6;
    }
  }
  cout << sum << endl;
  return 0;
}
