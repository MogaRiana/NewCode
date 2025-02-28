#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 2000;
const int K_MAX = 15;
const int INF = 2e9;

int N, M, K;
vector<pair<int, int>> G[N_MAX + 5];
int C[K_MAX + 5];
int dp[K_MAX + 5][1 << K_MAX];
bool vis[K_MAX + 5][1 << K_MAX];
int D[K_MAX + 5][N_MAX + 5];

void dijkstra(int index) {
  vector<bool> vis(N + 1);
  for (int i = 1; i <= N; i++) {
    D[index][i] = INF;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      Q;
  D[index][C[index]] = 0;
  Q.push({0, C[index]});
  while (!Q.empty()) {
    int cost = Q.top().first;
    int node = Q.top().second;
    Q.pop();
    if (vis[node]) {
      continue;
    }
    vis[node] = true;
    for (auto it : G[node]) {
      if (D[index][it.second] > D[index][node] + it.first) {
        D[index][it.second] = D[index][node] + it.first;
        Q.push({D[index][it.second], it.second});
      }
    }
  }
}

struct Stare {
  int cost;
  int i, conf;
};

struct cmp {
  bool operator()(Stare &a, Stare &b) { return a.cost > b.cost; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"ubuntzei.in"};
  ofstream cout{"ubuntzei.out"};

  cin >> N >> M;
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> C[i];
  }

  if (K == 0) {
    K = 2;
    C[0] = 1;
    C[1] = N;
  }

  for (int i = 1; i <= M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    G[x].push_back({c, y});
    G[y].push_back({c, x});
  }
  for (int i = 0; i < K; i++) {
    dijkstra(i);
  }

  for (int i = 0; i < K; i++) {
    for (int conf = 0; conf < (1 << K); conf++) {
      dp[i][conf] = INF;
    }
  }

  priority_queue<Stare, vector<Stare>, cmp> Q;
  for (int i = 0; i < K; i++) {
    Q.push({D[i][1], i, 1 << i});
    dp[i][1 << i] = D[i][1];
  }
  while (!Q.empty()) {
    Stare curr = Q.top();
    Q.pop();
    if (vis[curr.i][curr.conf]) {
      continue;
    }
    vis[curr.i][curr.conf] = true;
    for (int nxt = 0; nxt < K; nxt++) {
      if ((1 << nxt) & curr.conf) {
        continue;
      }
      if (dp[nxt][curr.conf + (1 << nxt)] >
          dp[curr.i][curr.conf] + D[curr.i][C[nxt]]) {
        dp[nxt][curr.conf + (1 << nxt)] =
            dp[curr.i][curr.conf] + D[curr.i][C[nxt]];
        Q.push({dp[nxt][curr.conf + (1 << nxt)], nxt, curr.conf + (1 << nxt)});
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < K; i++) {
    ans = min(ans, dp[i][(1 << K) - 1] + D[i][N]);
  }
  cout << ans << "\n";
  return 0;
}