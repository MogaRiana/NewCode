#include <iostream>

using namespace std;

int main() {
  int a = 2;
  int n;
  cin >> n;
  while (n > 0) {
    a *= 2;
    a -= 1;
    n -= 1;
  }
  cout << a * a << endl;

  return 0;
}
