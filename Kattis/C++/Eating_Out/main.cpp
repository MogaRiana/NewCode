#include <iostream>

using namespace std;

int main() {
  int m, a, b, c;
  cin >> m >> a >> b >> c;
  if (a + b + c <= 2 * m) {
    cout << "possible";
  } else {
    cout << "impossible";
  }
  return 0;
}
