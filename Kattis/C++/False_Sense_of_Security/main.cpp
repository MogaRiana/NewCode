#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

map<char, str> m1 = {
    {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
    {'F', "..-."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
    {'K', "-.-"},  {'L', ".-.."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'_', "..--"}, {'.', "---."}, {',', ".-.-"}, {'?', "----"},
};

map<str, char> m2 = {
    {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},  {".", 'E'},
    {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'}, {"..", 'I'},   {".---", 'J'},
    {"-.-", 'K'},  {".-..", 'L'}, {"--", 'M'},   {"-.", 'N'},   {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'},
    {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'}, {"..--", '_'}, {"---.", '.'}, {".-.-", ','}, {"----", '?'},
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  while (cin >> s) {
    str mm;
    vi64 nr;
    for (i64 i = 0; i < s.size(); i++) {
      str x = m1[s[i]];
      mm += x;
      nr.push_back(m1[s[i]].size());
    }

    i64 k = 0;
    for (i64 i = nr.size() - 1; i >= 0; i--) {
      str res;
      for (i64 j = k; j < k + nr[i]; j++) {
        res.push_back(mm[j]);
      }
      k += nr[i];
      cout << m2[res];
    }

    cout << endl;
  }

  return 0;
}