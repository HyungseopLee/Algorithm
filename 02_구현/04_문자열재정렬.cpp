#include <iostream>
#include <vector>

using namespace std;

int main(void){

    string user_input;
    getline(cin, user_input);

    int sum = 0;

    for (int i = 0 ; i < user_input.length(); i++)
    {
        if(user_input[i]-'0' >= 0 && user_input[i]-'0' <= 9) {
            sum += (user_input[i] - '0');
            user_input.erase(user_input.begin() + i);
            i--;
        }
    }
    
    sort(user_input.begin(), user_input.end());
    cout << user_input + to_string(sum) << endl;

    return 0;
}

/*
K1KA5CB7 -> ABCKK13

AJKDLSI412K4JSJ9D  -> ADDIJJJKKLSS20

*/