#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int A, B, C;
    string n;
    cin >> n;
    if(a < b && b < c){
        A = a;
        B = b;
        C = c;
    }
    else if(a > b && b > c){
        A = c;
        B = b;
        C = a;
    }
    else if(b > a && a > c){
        A = c;
        B = a;
        C = b;
    }
    else if(b > c && c > a){
        A = a;
        B = c;
        C = b;
    }
    else if(c > a && a > b){
        A = b;
        B = a;
        C = c;
    }
    else if(a > c && c > b){
        A = b;
        B = c;
        C = a;
    }

    if(n == "ABC"){
        cout << A << " " << B << " " << C << endl;
    }
    else if(n == "ACB"){
        cout << A << " " << C << " " << B << endl;
    }
    else if(n == "BAC"){
        cout << B << " " << A << " " << C << endl;
    }
    else if(n == "BCA"){
        cout << B << " " << C << " " << A << endl;
    }
    else if(n == "CAB"){
        cout << C << " " << A << " " << B << endl;
    }
    else if(n == "CBA"){
        cout << C << " " << B << " " << A << endl;
    }
    return 0;
}
