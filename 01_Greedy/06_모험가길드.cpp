#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int result = 0;
    int traveler;
    cin >> traveler;

    vector <int> scary;

    int user_input;
    for (int i = 0; i < traveler; i++)
    {
        cin >> user_input;
        scary.push_back(user_input);
    }
    sort(scary.begin(), scary.end());

    int cnt = 0;
    for (int i = 0; i < traveler; i++)
    {
        cnt += 1;
        if(cnt >= scary[i]) {
            result += 1;
            cnt = 0;
        }
    }
    
    cout << result << endl;

    return 0;
}

/*

5
2 3 1 2 2

*/