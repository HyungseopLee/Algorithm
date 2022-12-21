#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){

    string user_input;
    getline(cin,user_input);

    vector<int> arr;

    for (int i = 0; i < user_input.length(); i++)
    {
        arr.push_back(user_input[i] - '0');
    }
    
    int result = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if(result == 0 || result == 1 || arr[i] == 0 || arr[i] == 1) {
            result += arr[i];
        }
        else {
            result *= arr[i];
        }
    }

    cout << result;

    return 0;
}

/*

02984

576

*/