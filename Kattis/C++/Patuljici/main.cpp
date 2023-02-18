#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 arr[9], s = 0;
    for(i64 i = 0; i < 9; i++){
        cin >> arr[i];
        s += arr[i];
    }
    for(i64 i = 0; i < 9; i++){
        for(i64 j = 0; j < 9; j++){
            if(j == i){
                continue;
            }
            i64 d = arr[i] + arr[j];
            if(s - d == 100){
                i64 a = arr[i], b = arr[j];
                for(i64 k = 0; k < 9; k++){
                    if(arr[k] != a && arr[k] != b){
                        cout << arr[k] << endl;
                    }
                }
                return 0;
            }
        }
    }
}
