#include <iostream>
#include <vector>

using namespace std;

void show_map(vector<vector<int>> map){
    cout << endl;
    for (auto i : map)
    {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(void){

    int n, m;
    cin >> n >> m;

    int A, B, view;
    cin >> A >> B >> view;

    int result = 1;

    
    vector<vector<int>> map;

    for (int i = 0; i < n; i++)
    {
        vector <int> temp;
        for (int j = 0; j < m; j++)
        {
            int user_input;
            cin >> user_input;
            temp.push_back(user_input);
        }
        map.push_back(temp);
    }
    map[A][B] = 9; // start 위치
    
    int around = 0;    
    while(1) {

        if(around == 4) { // 동서남북 다 못 가는 길이라면 break
            break;
        }

        if(view == 0) { // 북쪽
            view = 3; // 동쪽을 바라보게 만듦
            if(map[A][B-1] != 0 || B-1 <= 1) { // 갈 수 없는 길
                around++;
                continue;
            }
            else { // 갈 수 있는 길이라면
                B = B - 1;
                map[A][B] = 2;
                result++;
                around = 0;
                show_map(map);
            }
        }
        else if(view == 1){ // 동쪽
            view = 0; // 북쪽을 바라보게 만듦
            if(map[A-1][B] != 0 || A-1 <= 1) { // 갈 수 없는 길
                around++;
                continue;
            }
            else { // 갈 수 있는 길이라면
                A = A - 1;
                map[A][B] = 2;
                result++;
                around = 0;
                show_map(map);
            }
        }
        else if(view == 2){ // 남쪽
            view = 3; // 서쪽을 바라보게 만듦
            if(map[A][B+1] != 0 || B+1 >= n) { // 갈 수 없는 길
                around++;
                continue;
            }
            else { // 갈 수 있는 길이라면
                B = B + 1;
                map[A][B] = 2;
                result++;
                around = 0;
                show_map(map);
            }
            
        }
        else if(view == 3){ // 서쪽
            view = 2; // 남쪽을 바라보게 만듦
            if(map[A+1][B] != 0 || A+1 >= m) { // 갈 수 없는 길
                around++;
                continue;
            }
            else { // 갈 수 있는 길이라면
                A = A + 1;
                map[A][B] = 2;
                result++;
                around = 0;
                show_map(map);
            }
            
        }

    }
    
    cout << result << endl;

    return 0;
}

/*

4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1

*/