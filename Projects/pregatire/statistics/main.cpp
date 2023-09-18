#include <iostream>

using namespace std;

int main() {
  int n, c = 1;
  while (cin >> n) {
    int maxx = -1e9, minn = 1e9, diff;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > maxx) {
        maxx = x;
      }
      if (x < minn) {
        minn = x;
      }
    }

    diff = maxx - minn;
    cout << "Case " << c << ": " << minn << " " << maxx << " " << diff << endl;
    c++;
  }
  return 0;
}
