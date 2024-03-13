#include <bits/stdc++.h>

using namespace std;

int power_of_two(int n) {
  int crt = 1;
  while (crt < n) {
    crt *= 2;
  }

  return crt * 2;
}

class SegmentTree {
private:
  int n;
  vector<int> tree;
  int len;

  void build(vector<int> &tr) {
    for (int i = 0; i < n; i++) {
      tree[i + len] = tr[i];
    }

    int start = len / 2;
    int end = len;
    while (start != 0) {
      for (int index = start; index < end; index++) {
        tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
      }
      start /= 2;
      end /= 2;
    }
  }

public:
  SegmentTree(vector<int> &tr) {
    n = tr.size();
    tree.resize(power_of_two(n), 0);
    len = tree.size() / 2;
    build(tr);
  }

  void update(int pos, int value) {
    pos = pos + len - 1;
    tree[pos] = value;

    while (pos != 0) {
      pos = pos / 2;
      tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
    }
  }

  int query(int l, int r) {
    l = l + len - 1;
    r = r + len - 1;
    int res = -1;

    while (l <= r) {
      if (l % 2 == 1) {
        res = max(res, tree[l]);
        l++;
      }
      if (r % 2 == 0) {
        res = max(res, tree[r]);
        r--;
      }
      r /= 2;
      l /= 2;
    }

    return res;
  }
};

int main() {
  ifstream cin{"arbint.in"};
  ofstream cout{"arbint.out"};

  int n, q;
  cin >> n >> q;

  vector<int> tree(n);

  for (int i = 0; i < n; i++) {
    cin >> tree[i];
  }

  SegmentTree CopilCopac(tree);

  for (int index = 0; index < q; index++) {
    int type, a, b;
    cin >> type >> a >> b;

    if (type == 0) {
      cout << CopilCopac.query(a, b) << '\n';
    } else {
      CopilCopac.update(a, b);
    }
  }

  return 0;
}