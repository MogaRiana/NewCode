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

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, m;
    cin >> n >> m;

    // car, {catalog price, pick-up cost, cost per kilometer}
    map<str, vi64> cost;
    for (i64 i = 0; i < n; i++) {
      str car;
      i64 p, q, k;
      cin >> car >> p >> q >> k;

      cost[car].push_back(p);
      cost[car].push_back(q);
      cost[car].push_back(k);
    }

    // name of the spy, true -> consistent / false -> inconsistent
    map<str, bool> ver;
    // name of the spy, car ("" if no car is picked-up), total cost
    map<str, pair<str, i64>> res;
    while (m--) {
      i64 time;
      cin >> time;

      str name;
      char event;
      cin >> name >> event;

      if (event == 'p') {
        str car;
        cin >> car;

        if (res.count(name) and ver[name]) {
          if (res[name].first == "") {
            res[name].first = car;
            res[name].second += cost[car][1];
          } else {
            ver[name] = false;
          }
        } else if (!res.count(name)) {
          res[name] = make_pair(car, cost[car][1]);
          ver[name] = true;
        }
      } else if (event == 'r') {
        i64 c;
        cin >> c;

        if (res.count(name) and ver[name]) {
          if (res[name].first != "") {
            res[name].second += c * cost[res[name].first][2];
            res[name].first = "";
          } else {
            ver[name] = false;
          }
        } else if (!res.count(name)) {
          ver[name] = false;
        }
      } else if (event == 'a') {
        double c;
        cin >> c;

        if (res.count(name) and ver[name]) {
          if (res[name].first != "") {
            double cr = c / 100.0 * cost[res[name].first][0];
            cr = ceil(cr);
            res[name].second += cr;
          } else {
            ver[name] = false;
          }
        } else if (!res.count(name)) {
          ver[name] = false;
        }
      }
    }

    for (auto &x : ver) {
      cout << x.first << " ";

      if (!x.second or res[x.first].first != "") {
        cout << "INCONSISTENT" << endl;
      } else {
        cout << res[x.first].second << endl;
      }
    }
  }

  return 0;
}