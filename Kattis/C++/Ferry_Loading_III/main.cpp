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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  i64 c;
  cin >> c;
  for (i64 tc = 0; tc < c; tc++) {
    if (tc > 0) {
      cout << endl;
    }

    i64 cap, cross_time, cars_no;
    cin >> cap >> cross_time >> cars_no;
    deque<p64> q[2];
    for (int i = 0; i < cars_no; i++) {
      i64 ct;
      string pos;
      cin >> ct >> pos;
      if (pos[0] == 'l') {
        q[0].push_back({ct, i});
      } else {
        q[1].push_back({ct, i});
      }
    }

    int ctime = 0;
    bool pos = false;
    deque<p64> sol;
    while (!q[0].empty() || !q[1].empty()) {
      deque<i64> load;
      int fcap = 0;
      while (!q[pos].empty() && fcap < cap && q[pos][0].first <= ctime) {
        load.push_back(q[pos][0].second);
        q[pos].pop_front();
        fcap++;
      }

      if (fcap > 0) {
        ctime += cross_time;
        pos = !pos;
        for (auto e : load) {
          sol.push_back({e, ctime});
        }

        load.clear();
      } else {
        if (!q[!pos].empty() && q[!pos][0].first <= ctime) {
          ctime += cross_time;
          pos = !pos;
        } else {
          if (!q[pos].empty()) {
            if (q[!pos].empty()) {
              ctime = q[pos][0].first;
            } else {
              if (q[pos][0].first < q[!pos][0].first) {
                ctime = q[pos][0].first;
              } else {
                if (q[!pos][0].first > ctime) {
                  ctime = q[!pos][0].first;
                }
                ctime += cross_time;
                pos = !pos;
              }
            }
          } else {
            if (!q[!pos].empty()) {
              if (q[!pos][0].first > ctime) {
                ctime = q[!pos][0].first;
              }
              ctime += cross_time;
              pos = !pos;
            } else {
              break;
            }
          }
        }
      }
    }

    sort(sol.begin(), sol.end());
    for (auto e : sol) {
      cout << e.second << endl;
    }
  }
  return 0;
}