#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i6) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int32_t i32;
typedef int16_t i16;
typedef vector<i32> vi32;
typedef vector<vi32> vv;
typedef string str;
typedef pair<i32, i32> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

class fentree {
private:
  vi32 ft;

public:
  fentree(i32 m) { ft.assign(m + 1, 0); }

  void update(i32 i, i32 val) {
    i32 crt = i + 1;
    while (crt < ft.size()) {
      ft[crt] += val;
      crt += LSOne(crt);
    }
  }

  i32 rsq(i32 j) {
    i32 crt = j + 1;
    i32 sum = 0;
    while (crt > 0) {
      sum += ft[crt];
      crt -= LSOne(crt);
    }

    return sum;
  }
  i32 rsq(i32 i, i32 j) { return rsq(j) - rsq(i - 1); }
};

struct query {
  i32 from, to;
  i32 x, y;
  i32 res = 0;

  bool operator<(const query &q) {
    if (from < q.from) {
      return true;
    }
    if (from == q.from) {
      return to < q.to;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"qxy.in"};
  ofstream cout{"qxy.out"};

  i32 n;
  cin >> n;

  vector<i16> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  i32 q;
  cin >> q;

  vector<query> qr(q);
  vector<i32> op(q), cl(q);
  for (i32 i = 0; i < q; i++) {
    cin >> qr[i].from >> qr[i].to >> qr[i].x >> qr[i].y;
    op[i] = i;
    cl[i] = i;
  }

  sort(op.begin(), op.end(),
       [&qr](i32 a, i32 b) { return qr[a].from < qr[b].from; });
  sort(cl.begin(), cl.end(),
       [&qr](i32 a, i32 b) { return qr[a].to < qr[b].to; });

  fentree ft(1002);
  i32 ind = 1;
  i32 oi = 0, ci = 0;

  for (auto &e : v) {
    while (oi < q and qr[op[oi]].from == ind) {
      i32 i = op[oi];
      qr[i].res -= ft.rsq(qr[i].x, qr[i].y);
      oi++;
    }

    ft.update(e, 1);

    while (ci < q and qr[cl[ci]].to == ind) {
      i32 i = cl[ci];
      qr[i].res += ft.rsq(qr[i].x, qr[i].y);
      ci++;
    }

    ind += 1;
  }

  for (auto &e : qr) {
    cout << e.res << endl;
  }

  return 0;
}