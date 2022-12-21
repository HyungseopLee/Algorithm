#include <iostream>

using namespace std;

int main(void){

    string user_input;

    getline(cin, user_input);
    int curX = user_input[0] - 'a' + 1; // a -> 1, b -> 2
    int curY = user_input[1] - '0';
    int cnt = 0;

    int move_steps[8][2] = {
        {-1, -2}, // x : -2, y : -1
        {-2, -1}, // x : -1, y : -2

        {1, -2}, // x : -2, y : 1
        {2, -1}, // x : -1, y : 2

        {-1, 2}, // x : 2, y : -1
        {-2, 1}, // x : 1, y : -2
        
        {1, 2}, // x : 2, y : 1
        {2, 1}  // x : 1, y : 2
    };

    for (int i = 0; i < 8; i++)
    {
        int tempX = curX + move_steps[i][0]; 
        int tempY = curY + move_steps[i][1];

        if((tempX >= 1 && tempX <= 8) && (tempY >= 1 && tempY <= 8)) {
            cnt++;
        }
    }

    cout << cnt << endl;
    

    return 0;
}