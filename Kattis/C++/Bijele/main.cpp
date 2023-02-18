#include <iostream>

using namespace std;

int main() {
  int k, q, r, b, kn, p;
  cin >> k >> q >> r >> b >> kn >> p;
  int k2 = k - 1, q2 = q - 1, r2 = r - 2, b2 = b - 2, kn2 = kn - 2, p2 = p - 8;

  cout << k2 * (-1) << " ";
  cout << q2 * (-1) << " ";
  cout << r2 * (-1) << " ";
  cout << b2 * (-1) << " ";
  cout << kn2 * (-1) << " ";
  cout << p2 * (-1) << " ";

  return 0;
}