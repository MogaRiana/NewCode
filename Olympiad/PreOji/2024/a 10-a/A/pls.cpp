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
    unordered_map<i64, i64> ind;
    unordered_set<i64> num;

    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    for (i64 i = 1; i <= n; i++) {
      i64 x = v[i - 1];

      ind[x] = i;

      if (num.count(x)) {
        ll++;
      } else {
        if (num.size() < 3) {
          num.insert(x);
          ll++;
        } else {
          unordered_set<i64> aux;
          i64 k;
          for (i64 j = i - 1; j > 0; j--) {
            aux.insert(v[j - 1]);
            if (aux.size() == 3) {
              k = j;
              break;
            }
          }

          vi64 pos;
          for (auto &c : ind) {
            if (c.sd <= k and num.count(c.ft)) {
              num.erase(c.ft);
            }
          }

          res = max(res, ll);
          ll -= k - er;
          er += k - er;
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