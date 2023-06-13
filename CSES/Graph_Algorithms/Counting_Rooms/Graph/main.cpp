#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

void bfs(vector<vector<i64>> &graph, vector<bool> &visited, i64 x) {
  deque<i64> q;
  q.push_back(x);
  visited[x] = true;

  while (!q.empty()) {
    auto crt = q.front();
    q.pop_front();
    visited[crt] = true;
    for (auto c : graph[crt]) {
      if (!visited[c]) {
        q.push_back(c);
        visited[c] = true;
      }
    }
  }
}

int main() {
  i64 l, c;
  cin >> l >> c;

  vector<vector<char>> v(l, vector<char>(c));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }

  vector<vector<i64>> graph(l * c);

  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (v[i][j] == '.') {
        if (i - 1 >= 0 and v[i - 1][j] == '.') {
          graph[i * c + j].push_back((i - 1) * c + j);
        }
        if (i + 1 < l and v[i + 1][j] == '.') {
          graph[i * c + j].push_back((i + 1) * c + j);
        }
        if (j - 1 >= 0 and v[i][j - 1] == '.') {
          graph[i * c + j].push_back(i * c + (j - 1));
        }
        if (j + 1 < c and v[i][j + 1] == '.') {
          graph[i * c + j].push_back(i * c + (j + 1));
        }
        graph[i * c + j].push_back(i * c + j);
      }
    }
  }

  vector<bool> visited(l * c, false);
  i64 res = 0;
  for (i64 x = 0; x < graph.size(); x++) {
    if (!visited[x] and graph[x].size() != 0) {
      bfs(graph, visited, x);
      res++;
    }
  }

  cout << res << endl;

  return 0;
}