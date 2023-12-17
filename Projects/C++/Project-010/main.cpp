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

struct student {
  str name;
  student *next;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  student *kid = new student;
  kid->name = "vasile";
  kid->next = new student;
  kid->next->name = "marcel";

  student *faur = new student;
  faur->name = "david";
  kid->next->next = faur;
  faur->next = NULL;

  student *crt = kid;
  while (crt != NULL) {
    cout << crt->name << endl;
    crt = crt->next;
  }

  return 0;
}
