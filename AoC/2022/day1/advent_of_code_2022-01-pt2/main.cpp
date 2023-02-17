#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  string a;
  v elf;
  i64 s = 0, sum = 0;
  while (getline(cin, a)) {
    i64 nr = 0;
    if (a == "") {
      elf.push_back(s);
      s = 0;
    } else {
      nr = stoi(a);
      s += nr;
    }
  }
  sort(elf.rbegin(), elf.rend());
  for (i64 i = 0; i < 3; i++) {
    sum += elf[i];
  }
  cout << sum << endl;
  return 0;
}
