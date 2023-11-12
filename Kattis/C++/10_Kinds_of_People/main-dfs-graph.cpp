#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool dfs(i64 start_node, i64 end_node, vv &v, vector<bool> &visit) {
  if (start_node == end_node) {
    return true;
  }

  if (!visit[start_node]) {
    visit[start_node] = true;
    for (auto &x : v[start_node]) {
      if (!visit[x]) {
        return dfs(x, end_node, v, visit);
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c;
  cin >> l >> c;

  vv v(l, vi64(c));
  for (i64 i = 0; i < l; i++) {
    str s;
    cin >> s;
    for (i64 j = 0; j < c; j++) {
      v[i][j] = s[j] - '0';
    }
  }

  vector<vector<i64>> graph_1(l * c);
  vector<vector<i64>> graph_0(l * c);

  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (v[i][j] == 1) {
        if (i - 1 >= 0 and v[i - 1][j] == 1) {
          graph_1[i * c + j].push_back((i - 1) * c + j);
        }
        if (i + 1 < l and v[i + 1][j] == 1) {
          graph_1[i * c + j].push_back((i + 1) * c + j);
        }
        if (j - 1 >= 0 and v[i][j - 1] == 1) {
          graph_1[i * c + j].push_back(i * c + (j - 1));
        }
        if (j + 1 < c and v[i][j + 1] == 1) {
          graph_1[i * c + j].push_back(i * c + (j + 1));
        }
        graph_1[i * c + j].push_back(i * c + j);
      }
    }
  }

  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (v[i][j] == 0) {
        if (i - 1 >= 0 and v[i - 1][j] == 0) {
          graph_0[i * c + j].push_back((i - 1) * c + j);
        }
        if (i + 1 < l and v[i + 1][j] == 0) {
          graph_0[i * c + j].push_back((i + 1) * c + j);
        }
        if (j - 1 >= 0 and v[i][j - 1] == 0) {
          graph_0[i * c + j].push_back(i * c + (j - 1));
        }
        if (j + 1 < c and v[i][j + 1] == 0) {
          graph_0[i * c + j].push_back(i * c + (j + 1));
        }
        graph_0[i * c + j].push_back(i * c + j);
      }
    }
  }

  i64 n;
  cin >> n;
  while (n--) {
    vector<bool> visit(l * c);

    pair<i64, i64> start;
    pair<i64, i64> endd;

    cin >> start.first >> start.second >> endd.first >> endd.second;
    start.first--;
    start.second--;
    endd.first--;
    endd.second--;

    i64 start_node = start.first * c + start.second;
    i64 end_node = endd.first * c + endd.second;

    if (graph_1[start_node].size()) {
      if (dfs(start_node, end_node, graph_1, visit)) {
        cout << "decimal" << endl;
      } else {
        cout << "neither" << endl;
      }
    } else if (graph_0[start_node].size()) {
      if (dfs(start_node, end_node, graph_0, visit)) {
        cout << "binary" << endl;
      } else {
        cout << "neither" << endl;
      }
    } else {
      cout << "neither" << endl;
    }
  }

  return 0;
}