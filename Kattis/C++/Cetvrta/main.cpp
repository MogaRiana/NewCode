#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x1 == x2 && x2 != x3){
        cout << x3 << " ";
    }
    if(x1 == x3 && x3 != x2){
        cout << x2 << " ";
    }
    if(x2 == x3 && x3 != x1){
        cout << x1 << " ";
    }
    if(y1 == y2 && y2 != y3){
        cout << y3 << endl;
    }
    if(y1 == y3 && y3 != y2){
        cout << y2 << endl;
    }
    if(y2 == y3 && y3 != y1){
        cout << y1 << endl;
    }
    return 0;
}
