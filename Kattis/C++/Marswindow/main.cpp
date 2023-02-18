#include <iostream>

using namespace std;

int main()
{
    int an;
    cin >> an;
    an = an * 12;
    int a = 0;
    for(int i = 0; i < 12; i++){
        if(an % 26 == 2){
            a = 1;
        }
        an = an - 1;
    }
    if(a == 1){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}
