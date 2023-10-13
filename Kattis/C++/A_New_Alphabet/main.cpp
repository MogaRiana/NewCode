#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef long double d6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  getline(cin, s);

  for (i64 i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'A') {
      cout << "@";
    } else if (s[i] == 'b' or s[i] == 'B') {
      cout << "8";
    } else if (s[i] == 'c' || s[i] == 'C') {
      cout << "(";
    } else if (s[i] == 'd' || s[i] == 'D') {
      cout << "|)";
    } else if (s[i] == 'e' || s[i] == 'E') {
      cout << "3";
    } else if (s[i] == 'f' || s[i] == 'F') {
      cout << "#";
    } else if (s[i] == 'g' || s[i] == 'G') {
      cout << "6";
    } else if (s[i] == 'h' || s[i] == 'H') {
      cout << "[-]";
    } else if (s[i] == 'i' || s[i] == 'I') {
      cout << "|";
    } else if (s[i] == 'j' || s[i] == 'J') {
      cout << "_|";
    } else if (s[i] == 'k' || s[i] == 'K') {
      cout << "|<";
    } else if (s[i] == 'l' || s[i] == 'L') {
      cout << "1";
    } else if (s[i] == 'm' || s[i] == 'M') {
      cout << "[]"
           << "\\"
           << "/"
           << "[]";
    } else if (s[i] == 'n' || s[i] == 'N') {
      cout << "[]"
           << "\\"
           << "[]";
    } else if (s[i] == 'o' || s[i] == 'O') {
      cout << "0";
    } else if (s[i] == 'p' || s[i] == 'P') {
      cout << "|D";
    } else if (s[i] == 'q' || s[i] == 'Q') {
      cout << "(,)";
    } else if (s[i] == 'r' || s[i] == 'R') {
      cout << "|Z";
    } else if (s[i] == 's' || s[i] == 'S') {
      cout << "$";
    } else if (s[i] == 't' || s[i] == 'T') {
      cout << "']['";
    } else if (s[i] == 'u' || s[i] == 'U') {
      cout << "|_|";
    } else if (s[i] == 'v' || s[i] == 'V') {
      cout << "\\"
           << "/";
    } else if (s[i] == 'w' || s[i] == 'W') {
      cout << "\\"
           << "/"
           << "\\"
           << "/";
    } else if (s[i] == 'x' || s[i] == 'X') {
      cout << "}{";
    } else if (s[i] == 'y' || s[i] == 'Y') {
      cout << "`/";
    } else if (s[i] == 'z' || s[i] == 'Z') {
      cout << "2";
    } else {
      cout << s[i];
    }
  }

  return 0;
}