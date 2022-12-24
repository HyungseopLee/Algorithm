#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int _a, int _b){
    if(_b < _a){
        return true;
    }
    return false;
}

int main(void){

    int user_input;
    cin >> user_input;
    getchar();

    int* arr = new int(user_input);

    for (int i = 0; i < user_input; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    
    sort(arr, arr + user_input, desc);

    for (int i = 0; i < user_input; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}

/*

3
15
27
12

*/