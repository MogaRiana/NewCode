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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str("There are two needles in this haystack with needles.");
  string str2("zzzzz");

  i64 f = str.find(str2);
  cout << f << endl;

  return 0;
}