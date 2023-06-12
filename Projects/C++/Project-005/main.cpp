#include <bits/stdc++.h>

using namespace std;

int c = 0;

void rr(int &a, int b) {
  a++;
  b -= a;

  c = a + b;
}

int main() {
  int a = 10;
  int b = 5;

  cout << c << endl;

  rr(a, b);

  cout << a << " " << b << endl;
  cout << c << endl;
}