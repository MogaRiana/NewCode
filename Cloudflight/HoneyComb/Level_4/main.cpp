#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

vi64 dirx = {-1, -1, 0, 0, 1, 1};
vi64 diry = {-1, 1, -2, 2, -1, 1};

bool bfs(vector<str> &v, pair<i64, i64> start) {
  deque<pair<i64, i64>> q;
  q.push_back({start.first, start.second});
  vector<vector<bool>> visit(v.size(), vector<bool>(v.front().size(), false));

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (i64 i = 0; i < 6; i++) {
      i64 x = cur.first + dirx[i];
      i64 y = cur.second + diry[i];
      if (x >= 0 and x < v.size() and y >= 0 and y < v[0].size() and
          !visit[x][y] and v[x][y] != 'X') {
        q.push_back({x, y});
      }
    }

    if (cur.first == v.size() - 1 or cur.first == 0 or cur.second == 0 or
        cur.second == v[0].size()) {
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("input4.txt");
  ofstream cout("output4.txt");

  i64 n;
  cin >> n;
  n++;

  while (n--) {
    str s;
    vector<str> v;

    while (getline(cin, s)) {
      if (s == "") {
        break;
      }

      v.push_back(s);
    }

    bool foundw = false;
    for (i64 i = 0; i < v.size(); i++) {
      for (i64 j = 0; j < v[0].size(); j++) {
        if (v[i][j] == 'W') {
          pair<i64, i64> start = {i, j};

          if (bfs(v, start)) {
            cout << "FREE" << endl;
          } else {
            cout << "TRAPPED" << endl;
          }

          foundw = true;
          break;
        }
      }

      if (foundw) {
        break;
      }
    }
  }

  return 0;
}