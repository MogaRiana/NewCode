#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(b - a < c - b){
        cout << (c - b) - 1;
    }
    else{
        cout << (b - a) - 1;
    }
    return 0;
}
