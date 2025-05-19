#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i64) x.size()
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

i64 res = -1;
vi64 v;
void calc(int i, int j, i64 summ) {
  if (i + 1 == j) {
    summ -= (v[i] + v[j] + v[j + 1]);
    summ += (v[i] * v[j] * v[j + 1]);
  } else {
    summ -= (v[i] + v[i + 1] + v[j] + v[j + 1]);
    summ += (v[i] * v[i + 1] + v[j] * v[j + 1]);
  }
  res = max(res, summ);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"expresie8.in"};
  ofstream cout{"expresie8.out"};

  int n;
  cin >> n;

  v.resize(n);
  i64 sum = 0;
  for (auto &i : v) {
    cin >> i;
    sum += i;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      calc(i, j, sum);
    }
  }

  cout << res << endl;

  return 0;
}