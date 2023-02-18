#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main()
{
    vi64 v(5);
    for(i64 i = 0; i < 5; i++){
        cin >> v[i];
    }
    bool ok = true;
    while(ok){
        if(v[0] > v[1]){
            swap(v[0], v[1]);
            cout << v[0] << " " << v[1] << " " <<  v[2] << " " <<  v[3] << " " <<  v[4] << endl;
        }

        if(v[1] > v[2]){
            swap(v[1], v[2]);
            cout << v[0] << " " << v[1] << " " <<  v[2] << " " <<  v[3] << " " <<  v[4] << endl;
        }

        if(v[2] > v[3]){
            swap(v[2], v[3]);
            cout << v[0] << " " << v[1] << " " <<  v[2] << " " <<  v[3] << " " <<  v[4] << endl;
        }

        if(v[3] > v[4]){
            swap(v[3], v[4]);
            cout << v[0] << " " << v[1] << " " <<  v[2] << " " <<  v[3] << " " <<  v[4] << endl;
        }

        if(v[4] > v[5]){
            swap(v[4], v[5]);
            cout << v[0] << " " << v[1] << " " <<  v[2] << " " <<  v[3] << " " <<  v[4] << endl;
        }

        if(v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5){
            ok = false;
        }
    }
    return 0;
}
