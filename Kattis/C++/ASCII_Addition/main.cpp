#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

const map<i64, str> m = {{0, "xxxxxx...xx...xx...xx...xx...xxxxxx"},
                         {1, "....x....x....x....x....x....x....x"},
                         {2, "xxxxx....x....xxxxxxx....x....xxxxx"},
                         {3, "xxxxx....x....xxxxxx....x....xxxxxx"},
                         {4, "x...xx...xx...xxxxxx....x....x....x"},
                         {5, "xxxxxx....x....xxxxx....x....xxxxxx"},
                         {6, "xxxxxx....x....xxxxxx...xx...xxxxxx"},
                         {7, "xxxxx....x....x....x....x....x....x"},
                         {8, "xxxxxx...xx...xxxxxxx...xx...xxxxxx"},
                         {9, "xxxxxx...xx...xxxxxx....x....xxxxxx"},
                         {10, ".......x....x..xxxxx..x....x......."}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<str> v(7);
  for (i64 i = 0; i < 7; i++) {
    cin >> v[i];
  }

  i64 k = 0;
  for (i64 i = 0; i < v.size(); i++) {
    for (i64 l = 0; l < 7; l++) {
      for (i64 c = k; i < k + 5; c++) {
      }
    }
  }

  return 0;
}
