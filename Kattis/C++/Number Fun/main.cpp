#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> n;
    while(n > 0){
        cin >> a >> b >> c;
        if(a + b == c || a - b == c || b - a == c || a * b == c){
            cout << "Possible" << endl;
        }
        else if(a / b == c && a % b == 0){
            cout << "Possible" << endl;
        }
        else if(b / a == c && b % a ==0){
            cout << "Possible" << endl;
        }
        else{
            cout << "Impossible" << endl;
        }

    n-=1;
    }
    return 0;
}
