#include <iostream>

using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  int p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    m = (x + m) - p[i];
  }
  cout << m + x;
  return 0;
}
