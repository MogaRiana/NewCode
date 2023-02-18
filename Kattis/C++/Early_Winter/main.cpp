#include <iostream>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    bool a = false;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(arr[i] <= d){
            cout << "It hadn't snowed this early in " << i << " years!";
            a = true;
            break;
        }
    }
    if(!a){
        cout << "It had never snowed this early!";
    }
    return 0;
}
