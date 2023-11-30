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

  ifstream cin("input2.txt");
  ofstream cout("output2.txt");

  i64 n;
  cin >> n;
  cin.ignore();

  vector<str> h0;
  vector<str> h1;
  vector<str> h21;
  vector<str> h22;
  vector<str> h3;
  vector<str> h4;

  map<str, i64> m;
  while (n--) {
    str s;
    getline(cin, s);

    i64 h = 0, k = 0;
    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] == 'H') {
        h++;
      } else if (s[i] == 'K') {
        k++;
      }
    }

    if (h == 0) {
      h0.push_back(s);
    } else if (h == 1) {
      h1.push_back(s);
    } else if (h == 2) {
      if (s[0] != s[1]) {
        h21.push_back(s);
      } else {
        h22.push_back(s);
      }
    } else if (h == 3) {
      h3.push_back(s);
    } else if (h == 4) {
      h4.push_back(s);
    }
  }

  if (h0.size()) {
    m[h0.front()] = h0.size();
  }
  if (h1.size()) {
    m[h1.front()] = h1.size();
  }
  if (h21.size()) {
    m[h21.front()] = h21.size();
  }
  if (h22.size()) {
    m[h22.front()] = h22.size();
  }
  if (h3.size()) {
    m[h3.front()] = h3.size();
  }
  if (h4.size()) {
    m[h4.front()] = h4.size();
  }

  for (auto &x : m) {
    cout << x.second << " " << x.first << endl;
  }

  return 0;
}