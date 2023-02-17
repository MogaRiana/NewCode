#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int nr[3];
    for(int i = 0; i < 3; i++){
        cin >> nr[i];
    }
    sort(nr, nr + 3);
    int a = nr[0], b = nr[1], c = nr[2];
    if(b - a == c - b){
        int d = c + (c - b);
        cout << d;
    }
    else if(b - a != c - b && c - b > b - a){
        int d = (b + c) / 2;
        cout << d;
    }
    else if(b - a != c - b && c - b < b - a){
        int d = (a + b) / 2;
        cout << d;
    }
    return 0;
}
