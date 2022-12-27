#include <iostream>

using namespace std;

int main(void){

    int x;
    cin >> x;

    // dp table 생성 후 0으로 초기화
    int* dp_table = new int[x+1]{0};
    
    // dp table 2, 3, 5 index 초기화
    dp_table[2] = 1; 
    dp_table[3] = 1;
    dp_table[5] = 1;

    for(int i = 4 ; i <= x ; i++){
        // 1을 뺐을 때의 연산횟수 == temp 라고 하자.
        dp_table[i] = dp_table[i-1] + 1; 

        // temp와 2로 나눴을 때의 연산횟수 중, 더 작은 값으로 갱신
        if(i % 2 == 0){
            dp_table[i] = min(dp_table[i], dp_table[i/2]+1);
        }
        // temp와 3로 나눴을 때의 연산횟수 중, 더 작은 값으로 갱신
        if(i % 3 == 0){
            dp_table[i] = min(dp_table[i], dp_table[i/3]+1);
        }
        // temp와 5로 나눴을 때의 연산횟수 중, 더 작은 값으로 갱신
        if(i % 5 == 0){
            dp_table[i] = min(dp_table[i], dp_table[i/5]+1);
        }
    }
    
    cout << dp_table[x] << endl;

    return 0;
}