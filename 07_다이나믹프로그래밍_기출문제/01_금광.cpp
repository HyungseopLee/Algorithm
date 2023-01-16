#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int t;
    cin >> t;

    for (int _t = 0; _t < t; _t++)
    {
        int n, m;
        cin >> n >> m;
        // dp table 생성, 초기화
        vector<vector<int>> dp_table;
        for (int _n = 0; _n < n; _n++)
        {
            vector<int> gold;
            for (int _m = 0; _m < m; _m++)
            {
                int temp;
                cin >> temp;
                gold.push_back(temp);
            }
            dp_table.push_back(gold);
        }
        cout << "here\n";

        // dp table update, 첫번째 열은 생략
        for (int _m = 1 ; _m < m; _m++)
        {
            for (int _n = 0; _n < n; _n++)
            {   
                int left_up = 0, left = 0, left_down = 0;
                // 왼쪽 위에서 못오는 경우
                if(_n == 0){
                    left_up = 0;
                }
                // 왼쪽 위에서 올 수 있는 경우
                else{
                    left_up = dp_table[_n-1][_m-1];
                }
                // 왼쪽 중간의 것을 오른쪽 위, 오른쪽, 오른쪽 아래 모두 갈 수 있다.
                left = dp_table[_n][_m-1];
                // 왼쪽 아래에서 못오는 경우
                if(_n == n - 1){
                    left_down = 0;
                }
                else{
                    left_down = dp_table[_n+1][_m-1];
                }
                dp_table[_n][_m] = dp_table[_n][_m] + max({left_up, left, left_down});
            }
        }
        // 마지막 열에서 최대값 찾아 출력
        int max = 0;
        for (int _n = 0; _n < n; _n++)
        {
            if(dp_table[_n][m-1] > max){
                max = dp_table[_n][m-1];
            }
        }
        cout << max << "\n";
    }

    return 0;
}

/*

2
3 4
1 3 3 2 2 1 4 1 0 6 4 7
4 4
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2

-> 19 16

*/