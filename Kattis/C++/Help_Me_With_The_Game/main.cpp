#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

void print(map<pair<i64, char>, vector<pair<i64, char>>> &m) {
  bool ok = true;
  for (auto &x : m) {
    for (i64 i = 0; i < x.second.size(); i++) {
      if (ok) {
        cout << ' ';
        ok = false;
      } else {
        cout << ',';
      }
      if (x.first.second != 'P') {
        cout << x.first.second;
      }
      cout << x.second[i].second << x.second[i].first;
    }
  }
}

map<pair<i64, char>, vector<pair<i64, char>>>
make(map<pair<i64, char>, vector<pair<i64, char>>> &m, str &s, i64 j, i64 posc,
     i64 posl) {
  if (s[j] == 'k' or s[j] == 'K') {
    m[{1, 'K'}].push_back({posc, posl});
  } else if (s[j] == 'q' or s[j] == 'Q') {
    m[{2, 'Q'}].push_back({posc, posl});
  } else if (s[j] == 'r' or s[j] == 'R') {
    m[{3, 'R'}].push_back({posc, posl});
  } else if (s[j] == 'b' or s[j] == 'B') {
    m[{4, 'B'}].push_back({posc, posl});
  } else if (s[j] == 'n' or s[j] == 'N') {
    m[{5, 'N'}].push_back({posc, posl});
  } else {
    m[{6, 'P'}].push_back({posc, posl});
  }

  return m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 posl = 8;
  str s;
  map<pair<i64, char>, vector<pair<i64, char>>> b;
  map<pair<i64, char>, vector<pair<i64, char>>> w;
  for (i64 i = 0; i < 8; i++, posl--) {
    char posc = 'a';
    cin >> s >> s;

    for (i64 j = 2; j < s.size(); j += 4, posc++) {
      if (s[j] >= 'a' and s[j] <= 'z') {
        make(b, s, j, posl, posc);
      } else if (s[j] >= 'A' and s[j] <= 'Z') {
        make(w, s, j, posl, posc);
      }
    }
  }
  cin >> s;

  for (auto &x : w) {
    sort(x.second.begin(), x.second.end());
  }

  cout << "White:";
  print(w);
  cout << endl;
  cout << "Black:";
  print(b);
  cout << endl;

  return 0;
}