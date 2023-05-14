#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
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

  str s;
  map<str, pair<pair<i64, i64>, i64>> cost;
  i64 day = 1;
  while (cin >> s) {
    if (s == "OPEN") {
      cost.clear();
    } else if (s == "ENTER") {
      str name;
      i64 nr;
      cin >> name >> nr;

      cost[name].first.first = nr;
    } else if (s == "EXIT") {
      str name;
      i64 nr;
      cin >> name >> nr;

      cost[name].first.second = nr;
      cost[name].second += cost[name].first.second - cost[name].first.first;
    } else if (s == "CLOSE") {
      cout << "Day " << day++ << endl;

      for (auto x : cost) {
        double d = x.second.second * 0.10;

        cout.precision(2);
        cout << fixed << x.first << " $" << d << endl;
      }

      cout << endl;
    }
  }

  return 0;
}