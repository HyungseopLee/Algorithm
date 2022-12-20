#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    int user_input;
    cin >> n;
    cin >> m;

    vector <vector <int>> arr;
    vector <int> min_arr;

    for (int i = 0; i < n; i++)
    {
        int min = 999;
        vector <int> temp;
        for (int j = 0; j < m; j++)
        {
            cin >> user_input;
            temp.push_back(user_input);
            if(min > user_input){
                min = user_input;
            }
        }
        arr.push_back(temp);
        min_arr.push_back(min);
    }
    
    sort(min_arr.begin(), min_arr.end());
    cout << min_arr[n-1];

    return 0;
}

/*

3 3
3 1 2
4 1 4
2 2 2

2 4
7 3 1 8
3 3 3 4

*/