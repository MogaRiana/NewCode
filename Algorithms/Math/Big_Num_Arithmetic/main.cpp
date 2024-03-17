#include <bits/stdc++.h>

using namespace std;

int Divide(int x[], int n)
// x = x /n, returneaza x%n
{
  int i, r = 0;
  for (i = x[0]; i > 0; i--) {
    r = 10 * r + x[i];
    x[i] = r / n;
    r %= n;
  }
  for (; x[x[0]] == 0 && x[0] > 1;)
    x[0]--;
  return r;
}

void Mult(int x[], int n)
// x <- x*n
{
  int i, t = 0;
  for (i = 1; i <= x[0]; i++, t /= 10) {
    t += x[i] * n;
    x[i] = t % 10;
  }
  for (; t; t /= 10)
    x[++x[0]] = t % 10;
}

int main() {
  string s;
  int n;
  cin >> s;
  cin >> n;

  int x[100], y[100];
  x[0] = s.size();
  for (int i = 1; i <= x[0]; i++) {
    x[i] = s[s.size() - 1] - '0';
    y[i] = s[s.size() - 1] - '0';
    s.pop_back();
  }

  Mult(x, n);
  for (int i = x[0]; i > 0; i--) {
    cout << x[i];
  }

  int r = Divide(y, n);
  for (int i = x[0]; i > 0; i--) {
    cout << x[i];
  }
  cout << endl;
  cout << r << endl;

  return 0;
}