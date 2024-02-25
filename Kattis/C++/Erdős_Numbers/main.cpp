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

unordered_map<str, i64> bfs(unordered_map<str, vector<str>> &ll) {
  unordered_map<str, i64> dist;
  dist["PAUL_ERDOS"] = 0;

  queue<str> q;
  q.push("PAUL_ERDOS");

  while (!q.empty()) {
    str u = q.front();
    q.pop();

    for (str v : ll[u]) {
      if (dist.count(v)) {
        if (dist[u] + 1 < dist[v]) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      } else {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;

  unordered_map<str, vector<str>> list;
  vector<str> nms;

  while (getline(cin, s)) {
    stringstream ss(s);
    str name;
    ss >> name;

    str x;
    while (ss >> x) {
      list[name].push_back(x);
      list[x].push_back(name);
    }

    nms.push_back(name);
  }

  unordered_map<str, i64> m = bfs(list);

  for (auto &x : nms) {
    if (m.count(x)) {
      cout << x << " " << m[x] << endl;
    } else {
      cout << x << " no-connection" << endl;
    }
  }

  return 0;
}