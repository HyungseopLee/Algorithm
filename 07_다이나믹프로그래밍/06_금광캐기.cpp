#include <iostream>
#include <vector>

using namespace std;

int main(void){

    // test case 개수 입력 받기
    int t;
    cin >> t;

    // test case만큼 실행
    for (int _t = 0; _t < t; _t++)
    {
        // 행개수 n, 열개수 m 입력받기
        int n, m;
        cin >> n >> m;

        // 행 개수 n, 열 개수 m, 0으로 초기화
        vector<vector<int>> dp_table;

        // dp_table 입력받기
        for (int _n = 0; _n < n; _n++)
        {
            vector<int> temp_vec;
            for (int _m = 0; _m < m; _m++)
            {
                int temp;
                cin >> temp;
                temp_vec.push_back(temp);
            }
            dp_table.push_back(temp_vec);
        }
        // dp_table 초기화 (첫 번째 열만 입력)
        for (int _n = 0; _n < n; _n++)
        {
            dp_table[_n][0] = dp_table[_n][0];
        }

        // dp_table update (열 개수만큼 진행, 첫번째 열은 건너뜀)
        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int left_up=0, left=0, left_down=0;
                // 왼쪽 위에서 오는 금광인 경우
                if(i == 0) {
                    left_up = 0;
                }
                else {
                    left_up = dp_table[i-1][j-1];
                }
                // 왼쪽에서 오는 금광인 경우
                left = dp_table[i][j-1];
                // 왼쪽 아래에서 오는 금광인 경우
                if(i == n-1) {
                    left_down = 0;
                }
                else {
                    left_down = dp_table[i+1][j-1];
                }
                dp_table[i][j] = dp_table[i][j] + max({left_up, left, left_down});
            }
        }
        // 마지막 열에서 최대값이 결과이므로 출력
        int max = 0;
        for (int _n = 0; _n < n; _n++)
        {
            if(max < dp_table[_n][m-1]){
                max = dp_table[_n][m-1];
            }
        }
        cout << max << endl;
        
    }

    return 0;
}

/*

2
3 4
1 3 3 2 2 1 4 1 0 6 4 7
4 4
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2

*/