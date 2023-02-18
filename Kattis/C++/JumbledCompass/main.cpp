#include <iostream>

using namespace std;

int main() {
  int n1, n2;
  cin >> n1 >> n2;
  int t = n2 - n1;
  if (t > 180) {
    t = t - 360;
  } else if (t < -180) {
    t = t + 360;
  } else if (t == -180) {
    t = 180;
  }
  cout << t << endl;
  return 0;
}
