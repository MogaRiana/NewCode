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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, x;
  cin >> n >> x;
  int m1 = n / 2, m2 = n - m1;

  vi64 v1(m1), v2(m2);
  for (int i = 0; i < m1; i++) {
    cin >> v1[i];
  }
  for (int i = 0; i < m2; i++) {
    cin >> v2[i];
  }

  vi64 sum1, sum2;
  for (int i = 0; i < (1 << m1); i++) {
    i64 cur = 0;
    for (int j = 0; j < m1; j++)
      if (i & (1 << j))
        cur += v1[j];
    sum1.push_back(cur);
  }
  for (int i = 0; i < (1 << m2); i++) {
    i64 cur = 0;
    for (int j = 0; j < m2; j++)
      if (i & (1 << j))
        cur += v2[j];
    sum2.push_back(cur);
  }

  srt(sum1);
  srt(sum2);

  i64 sum = 0;
  for (i64 s1 : sum1) {
    sum += upper_bound(sum2.begin(), sum2.end(), x - s1) -
           lower_bound(sum2.begin(), sum2.end(), x - s1);
  }

  cout << sum << endl;

  return 0;
}