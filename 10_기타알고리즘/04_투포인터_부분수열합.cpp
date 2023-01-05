// 특정한 합을 가지는 부분 수열 찾기

#include <iostream>

using namespace std;

int main(void){
    
    int n = 5, m = 5;
    int arr[] = {1, 2, 3, 2, 5};
    int cnt = 0, end = 0;

    for (int start = 0; start < n; start++)
    {
        int local_sum = arr[start];
        while(1){
            local_sum += arr[end];
            if(start == end) {
                local_sum -= arr[end];
            }
            if(local_sum == m) {
                cnt += 1;
                break;
            }
            if(local_sum > m){
                break;
            }
            else if(local_sum < m){
                end += 1;
            }
        }
        
    }

    cout << cnt << endl;
    

    return 0;
}

/*
3
*/