#include <iostream>
#include <vector>

using namespace std;

void showDP(vector<int>& _dp){
    cout << endl;
    for(auto i : _dp){
        cout << i << " ";
    }
    cout << endl;
}

int main(void){

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    // DP Table 1로 초기화
    vector<int> dp(n, 1); 
    int result = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // 내림차순을 만족할 때만 Dp Table update
            if(dp[j] > dp[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                if(result > dp[i]) {
                    result = dp[i];
                }
            }
        }
    }

    showDP(dp);
    
    cout << result << endl;

    return 0;
}

/*

7
15 11 4 8 5 2 4

*/