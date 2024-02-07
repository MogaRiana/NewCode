#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;
typedef string str;

map<str, vector<str>> make(str line, map<str, vector<str>> &m) {
  stringstream sstream(line);
  string s;

  sstream >> s;
  str name = s;

  while (sstream >> s) {
    m[s].push_back(name);
  }

  return m;
}

int main() {
  i64 n;
  while (cin >> n and n != 0) {
    map<str, vector<str>> m;
    str l;
    getline(cin, l);

    for (i64 i = 0; i < n; i++) {
      getline(cin, l);
      make(l, m);
    }

    for (auto &x : m) {
      cout << x.first << " ";
      for (i64 i = 0; i < x.second.size(); i++) {
        cout << x.second[i] << " ";
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}