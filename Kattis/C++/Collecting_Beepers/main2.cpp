#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2) {
  return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc += 1) {
    int c, r, n;
    cin >> c >> r;
    pair<int, int> st;
    cin >> st.first >> st.second;
    cin >> n;
    vector<pair<int, int>> pt(n);
    vector<int> pn(n);
    for (int i = 0; i < n; i++) {
      cin >> pt[i].first >> pt[i].second;
      pn[i] = i;
    }

    int md = 1e9;
    do {
      int d = 0;
      for (int i = 1; i < n; i++) {
        d += dist(pt[pn[i]], pt[pn[i - 1]]);
      }
      d += dist(pt[pn[n - 1]], st);
      d += dist(st, pt[pn[0]]);
      md = min(md, d);
    } while (next_permutation(pn.begin(), pn.end()));
    cout << md << endl;
  }
  return 0;
}