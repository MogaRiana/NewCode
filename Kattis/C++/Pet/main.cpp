#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    int i = 1;
    int t = 0;
    int m = 0;
    int n = 0;
    while (i <= 5){
        cin >> a >> b >> c >> d;
        t = a + b + c + d;
        if(t > m){
            m = t;
            n = i;
        }
        i += 1;
    }
    cout << n << " " << m << endl;
    return 0;
}
