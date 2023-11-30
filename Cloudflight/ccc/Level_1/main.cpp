#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("input1.txt");
  ofstream cout("output1.txt");

  i64 n;
  cin >> n;
  cin.ignore();

  map<str, i64> m;
  while (n--) {
    str s;
    getline(cin, s);

    m[s]++;
  }

  for (auto &x : m) {
    cout << x.second << "   " << x.first << endl;
  }

  return 0;
}