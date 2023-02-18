#include <iostream>

using namespace std;

int main() {
  int n, x, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i += 1) {
    cin >> x;
    if (x < 0) {
      sum += x;
    }
  }
  cout << (-sum);
  return 0;
}