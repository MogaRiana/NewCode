#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int a1 = 0;
    int b1 = 0;
    while (a > 0) {
        int res = a % 10;
        a1 = a1 * 10 + res;
        a /= 10;
    }
    while(b > 0){
        int res2 = b % 10;
        b1 = b1 * 10 + res2;
        b/= 10;
    }
    if(a1 > b1){
        cout << a1;
    }
    else{
        cout << b1;
    }
    return 0;
}
