#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  i64 a, b, x, y, crt = 0;
  char c, m, n;
  while (cin >> a >> m >> b >> c >> x >> n >> y) {
    if (a <= x && b >= y) {
      crt++;
    } else if (x <= a && y >= b) {
      crt++;
    }
  }
  cout << crt << endl;
  return 0;
}
