#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    while(cin >> a >> b >> c) {
        if(a == 0 && b == 0 && c == 0) {
            return 0;
        }
        else {
            if(a > b){
                int i = a;
                a = b;
                b = i;
            }
            if(a > c){
                int i = a;
                a = c;
                c = i;
            }
            if(b > c){
                int i = b;
                b = c;
                c = i;
            }
            if((c*c) == (a*a) + (b*b)){
                cout << "right" << endl;
            }
            else{
                cout << "wrong" << endl;
            }
        }
    }
}
