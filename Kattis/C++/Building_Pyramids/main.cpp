#include <iostream>

using namespace std;

int main() {
  int n, a = 0, s = 0;
  bool ok = true;
  cin >> n;
  while (ok) {
    a++;
    long long k = (2 * a - 1) * (2 * a - 1);
    if (s + k <= n) {
      s += k;
    } else {
      ok = false;
    }
  }
  cout << a - 1 << endl;
  return 0;
}
