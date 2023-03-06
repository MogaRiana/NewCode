
#include <iostream>

using namespace std;

int main() {
  int n;
  int d[6] = {0, 0, 0, 0, 0, 0};
  int p[6] = {-1, -1, -1, -1, -1, -1};
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    d[x - 1] += 1;
    if (p[x - 1] == -1) {
      p[x - 1] = i;
    }
  }
  int res = -1;
  for (int i = 0; i < 6; i++) {
    if (d[i] == 1) {
      res = p[i] + 1;
    }
  }
  if (res == -1) {
    cout << "none" << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}