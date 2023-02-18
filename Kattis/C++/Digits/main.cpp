#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    while(s != "END"){
        int l = s.size();
        int nrc = 0;
        if(s == "1"){
            cout << 1 << endl;
        }
        else{
            int step = 1;
            while(true){
                int a = l;
                while(a > 0){
                    a /= 10;
                    nrc++;
                }
                if(l == nrc){
                    cout << step + 1 << endl;
                    break;
                }
                step++;
                l = nrc;
                nrc = 0;
            }
        }
        cin >> s;
    }
    return 0;
}
