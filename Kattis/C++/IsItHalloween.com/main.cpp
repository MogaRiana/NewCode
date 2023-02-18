#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main()
{
    string s;
    i64 n;
    cin >> s >> n;
    if(s == "OCT" && n == 31){
        cout << "yup" << endl;
    }
    else if(s == "DEC" && n == 25){
        cout << "yup" << endl;
    }
    else{
        cout << "nope" << endl;
    }
    return 0;
}
