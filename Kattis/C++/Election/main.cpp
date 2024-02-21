#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;

  cin >> n;
  cin.ignore();
  map<str, str> teams;
  for (i64 i = 0; i < n; i++) {
    str name, team;
    getline(cin, name);
    getline(cin, team);
    teams[name] = team;
  }

  cin >> m;
  cin.ignore();
  map<str, i64> votes;
  for (i64 i = 0; i < m; i++) {
    str name;
    getline(cin, name);
    votes[name]++;
  }

  pair<i64, str> win = {-1, ""};
  bool k = true;
  for (auto &x : votes) {
    if (x.second > win.first) {
      win.first = x.second;
      win.second = x.first;
      k = true;
    } else if (x.second == win.first) {
      k = false;
    }
  }

  if (k) {
    cout << teams[win.second] << endl;
  } else {
    cout << "tie" << endl;
  }

  return 0;
}