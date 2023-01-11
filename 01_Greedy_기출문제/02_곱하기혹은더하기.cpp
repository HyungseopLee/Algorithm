#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){

    string str;
    getline(cin, str);
    vector<int> arr;
    long long result = 0;

    for(auto i : str){
        arr.push_back(i - '0');
    }

    result = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        // 0이나 1은 곱하는 것보다 더하는 것이 항상 더 큰 값을 만들 수 이다.
        // 나머지값은 곱하는 것이 항상 더 큰 값을 만들 수 있다.
        if(result <= 1 || arr[i] <= 1){
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

02984   -->  576

567    ---> 210

*/