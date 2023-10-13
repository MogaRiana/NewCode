#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef long double d6;

bool verify(char c) {
  if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y') {
    return true;
  }

  return false;
}

i64 make_word(str &s) {
  i64 p;
  for (i64 i = 0; i < s.size(); i++) {
    if (verify(s[i])) {
      p = i;
      break;
    }
  }

  return p;
}

void print(i64 p, str &s) {
  for (i64 i = p; i < s.size(); i++) {
    cout << s[i];
  }
  for (i64 i = 0; i < p; i++) {
    cout << s[i];
  }

  if (!p) {
    cout << "yay ";
  } else {
    cout << "ay ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  while (getline(cin, s)) {
    str cuv;
    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        i64 p = make_word(cuv);
        print(p, cuv);
        cuv.clear();
      } else {
        cuv.push_back(s[i]);
      }
    }

    i64 p = make_word(cuv);
    print(p, cuv);
    cout << endl;
  }

  return 0;
}
