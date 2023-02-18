#include <iostream>

using namespace std;

int main() {
  int p, n, wp = -1, w = 0;
  cin >> p >> n;
  for (int i = 1; i <= p; i++) {
    int crt = 0;
    for (int j = 1; j <= n; j++) {
      string corr;
      if (j % 15 == 0) {
        corr = "fizzbuzz";
      } else if (j % 5 == 0) {
        corr = "buzz";
      } else if (j % 3 == 0) {
        corr = "fizz";
      } else {
        corr = to_string(j);
      }
      string ans;
      cin >> ans;
      if (ans == corr) {
        crt++;
      }
    }
    if (crt > wp) {
      wp = crt;
      w = i;
    }
  }
  cout << w << endl;
  return 0;
}