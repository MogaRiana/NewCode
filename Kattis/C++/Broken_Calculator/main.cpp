#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a, b, s;
    char c;
    cin >> a >> c >> b;
    if(c == '+') {
        s = (a + b) - 1;
        cout << s << endl;
    }
    if(c == '-') {
        s = a - b;
        cout << s << endl;
    }
    if(c == '*') {
        s = (a * b) * (a * b);
        cout << s << endl;
    }
    if(c == '/') {
        if(a % 2 == 0) {
            s = a / 2;
            cout << s << endl;
        }
        else {
            s = (a + 1) / 2;
            cout << s << endl;
        }
    }
    for(int i = 1; i < n; i++) {
        cin >> a >> c >> b;
        if(c == '+') {
            s = (a + b) - s;
            cout << s << endl;
        }
        if(c == '-') {
            s *= a - b;
            cout << s << endl;
        }
        if(c == '*') {
            s = (a * b) * (a * b);
            cout << s << endl;
        }
        if(c == '/') {
            if(a % 2 == 0) {
                s = a / 2;
                cout << s << endl;
            }
            else {
                s = (a + 1) / 2;
                cout << s << endl;
            }
        }
    }
    return 0;
}
