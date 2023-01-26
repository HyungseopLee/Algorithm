#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<vector<int>> arrs;
    
    for (int i = 1; i <= n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i; j++)
        {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        arrs.push_back(temp);
    }
    
    for (int i = 1; i < arrs.size(); i++)
    {
        int len = arrs[i].size();
        for (int j = 0; j < len ; j++)
        {
            int left = 0;
            int right = 0;
            // 왼쪽 위에서 내려올 수 있는 경우
            if(j != 0){
                left = arrs[i-1][j-1];
            }
            // 오른쪽 위에서 내려올 수 있는 경우
            if(j != len - 1){
                right = arrs[i-1][j];
            }
            arrs[i][j] += max(left, right);
        }
    }
    // 마지막 행에서 가장 큰 숫자 출력
    int result = 0;
    for (int i = 0; i < arrs[n-1].size(); i++)
    {
        if(result < arrs[n-1][i]){
            result = arrs[n-1][i];
        }
    }
    cout << result;
    

    return 0;
}

/*

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
-> 30
*/