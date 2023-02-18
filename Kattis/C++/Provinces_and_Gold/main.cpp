#include <iostream>

using namespace std;

int main()
{
    int g, s, c;
    cin >> g >> s >> c;
    int gp = g * 3;
    int sp = s * 2;
    int cp = c * 1;
    int t = gp + sp + cp;
    if(t <= 1){
        cout << "Copper" << endl;
    }
    else if(t == 2){
        cout << "Estate or Copper" << endl;
    }
    else if(t >= 8){
        cout << "Province or Gold" << endl;
    }
    else if(t == 6 || t == 7){
        cout << "Duchy or Gold" << endl;
    }
    else if(t == 5){
        cout << "Duchy or Silver" << endl;
    }
    else if(t == 4 || t == 3){
        cout << "Estate or Silver" << endl;
    }
    else if(t == 2){
        cout << "Estate or Copper" << endl;
    }
    return 0;

}
