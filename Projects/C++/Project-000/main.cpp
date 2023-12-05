#include <bits/stdc++.h>

using namespace std;

class Pair {
private:
  int aa;

public:
  int first;
  int second;

  int add(int a, int b) { return a + b; }
};

int main() {
  Pair a;
  a.first = 1;
  a.second = 2;

  a.add(a.first, a.second);

  return 0;
}