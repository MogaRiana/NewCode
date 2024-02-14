#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;
typedef string str;

map<str, set<str>> make(str line, map<str, set<str>> &m) {
  stringstream sstream(line);
  string s;

  sstream >> s;
  str name = s;

  while (sstream >> s) {
    m[s].insert(name);
  }

  return m;
}

int main() {
  i64 n;
  while (cin >> n and n != 0) {
    map<str, set<str>> m;
    str l;
    getline(cin, l);

    for (i64 i = 0; i < n; i++) {
      getline(cin, l);
      make(l, m);
    }

    for (auto &x : m) {
      cout << x.first << " ";
      for (auto &name : x.second) {
        cout << name << " ";
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}