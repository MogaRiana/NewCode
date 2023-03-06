#include <iostream>

using namespace std;

int main() {
  int n, x = 7;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    if (b == "op!" && x < 10) {
      x++;
    } else if (b == "ned!" && x > 0) {
      x--;
    }
  }
  cout << x;
  return 0;
}