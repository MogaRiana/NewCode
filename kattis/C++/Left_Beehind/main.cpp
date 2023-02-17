#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int n = 1;
    while(n>0){
    cin >> a >> b;
    if(a > b && a + b != 13){
        cout << "To the convention." << endl;
    }
    else if(a + b == 13){
        cout << "Never speak again." << endl;
    }
    else if(a < b){
        cout << "Left beehind." << endl;
    }
    else if(a == b & a != 0 && b != 0){
        cout << "Undecided." << endl;
    }
    else if(a == 0 && b == 0){
        return 0;
    }
    }
}
