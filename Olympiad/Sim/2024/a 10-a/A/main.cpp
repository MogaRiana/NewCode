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

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"3secv.in"};
  ofstream cout{"3secv.out"};

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    i64 ll = 0, res = -1, er = 0;
    map<i64, i64> ind, nr;
    set<i64> num;
    for (i64 i = 1; i <= n; i++) {
      i64 x;
      cin >> x;

      ind[i] = x;
      nr[x] = i;

      if (num.count(x)) {
        ll++;
      } else {
        if (num.size() < 3) {
          num.insert(x);
          ll++;
        } else {
          i64 p = nr[ind.begin()->sd] - er;
          er += p;
          res = max(res, ll);
          ll -= p;

          vp64 pos;
          i64 mm = ind.begin()->ft;
          for (auto &c : ind) {
            if (c.ft <= mm) {
              pos.push_back({c.ft, c.sd});
            }
          }

          for (auto &c : pos) {
            ind.erase(c.ft);
            num.erase(c.sd);
            nr.erase(c.sd);
          }

          num.insert(x);
          ll++;
        }
      }
    }

    res = max(res, ll);
    cout << res << endl;
  }

  return 0;
}