#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<int> left_ice, right_ice;
    int flag=0;
    int my_pos;

    for (int i = 0; i < n; i++)
    {
        int user_input;
        cin >> user_input;
        if(user_input == -1){
            flag=1;
        }
        if(flag== 0){
            left_ice.push_back(user_input);
        }
        else{
            right_ice.push_back(user_input);
        }
    }   
    sort(left_ice.begin(), left_ice.end());
    sort(right_ice.begin(), right_ice.end());
    cout << left_ice[0] + right_ice[1];
    

    return 0;
}