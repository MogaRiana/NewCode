#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a = 0;
  while (n--) {
    int t;
    cin >> t;
    if (t < 0) {
      a += 1;
    }
  }
  cout << a << endl;
  return 0;
}
