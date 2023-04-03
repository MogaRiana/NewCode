/*
find a way out of a labyrinth
OXXOOOX
XOOOXXO
XOOXSXX
OOOOXXX
OOXOXXX
*/

#include <bits/stdc++.h>

using namespace std;

const vector<int> dirx = {1, -1, 0, 0};
const vector<int> diry = {0, 0, 1, -1};

bool bfs(vector<vector<char>> &eep, pair<int, int> start) {
  deque<pair<int, int>> q;
  q.push_back({start.first, start.second});
  vector<vector<bool>> visit(eep.size(),
                             vector<bool>(eep.front().size(), false));

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (int i = 0; i < 4; i++) {
      int x = cur.first + dirx[i];
      int y = cur.second + diry[i];
      if (x >= 0 and x < eep.size() and y >= 0 and y < eep.front().size() and
          !visit[x][y] and eep[x][y] != 'X') {
        q.push_back({x, y});
      }
    }

    if (cur.first == eep.size() - 1 or cur.first == 0 or cur.second == 0 or
        cur.second == eep.front().size()) {
      return true;
    }
  }

  return false;
}

int main() {
  int lin, col;
  cin >> lin >> col;

  vector<vector<char>> eep(lin, vector<char>(col));

  pair<int, int> start;
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      cin >> eep[i][j];
      if (eep[i][j] == 'S') {
        start.first = i;
        start.second = j;
      }
    }
  }

  if (bfs(eep, start)) {
    cout << "Found" << endl;
  } else {
    cout << "Not Found" << endl;
  }

  return 0;
}