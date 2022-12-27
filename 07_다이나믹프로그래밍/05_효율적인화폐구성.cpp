#include <iostream>
#include <vector>

// 화폐 가치 m은 최대 10,000까지 입력이 되니까
// 갖고 있는 화폐로 화폐 가치를 만들 수 없는 경우, dp_table에 해당 값을 INF로 처리
#define INF 10001

using namespace std;

void showDP(vector<int>& _dp){
    cout << endl;
    for (auto i : _dp)
    {
        cout << i << " ";
    }
    cout << endl;
    
}

int main(void){

    // 화폐 종류의 개수 n, 만들어야 할 화페 가치 m 입력받기 
    int n, m;
    cin >> n >> m;

    // 화폐 종류 입력받기
    vector <int> currencies;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        currencies.push_back(temp);
    }
    // 모두 10,001원으로 초기화
    vector<int> dp_table(m+1, INF);
    dp_table[0] = INF;
    // dp_table의 해당 화폐가치 인덱스에 1로 세팅
    // 2원 -> dp_table[2] = 1
    for (int i = 0; i < n; i++)
    {
        dp_table[currencies[i]] = 1; 
    }
    
    // dp_table 업데이트 (Bottom-Up)
    for (int i = 0; i < n; i++)
    {
        showDP(dp_table);
        // j = currencies[i]인 이유 : 그 다음 화폐를 사용했을 때의 최소개수를 update시켜야 하니까
        for(int j = currencies[i] ; j <= m ; j++){
            // (i-k)원을 만들 수 있는 경우에만 DP Table update
            if(dp_table[j - currencies[i]] != INF) {
                dp_table[j] = min(dp_table[j], dp_table[j - currencies[i]] + 1);
            }
        }
    }
    
    if(dp_table[m] == INF){
        cout << -1 << endl;
    }
    else{
        cout << dp_table[m] << endl;
    }

    return 0;
}

/*

2 15
2
3

3 4
3
5
7

*/