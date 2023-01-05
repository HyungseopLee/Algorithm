#include <iostream>
#include <cmath>

using namespace std;

void Eratosthenes(int n, bool* arr) {
    for (int i = 2; i <= sqrt(n); i++)
    {
        // 남은 수를 제외한 남은수의 배수들 지우기(false 만들기)
        if(arr[i]) {
            int j = 2;
            while(i * j <= n) {
                arr[i * j] = false;
                j += 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if(arr[i]){
            cout << i << " ";
        }
    }
}

int main(void){

    // 2 ~ 1,000까지 소수의 개수 구하기
    int n = 1000;

    // 2 ~ 1,0000 True로 초기화 (True : 소수, False : 소수 아님)
    bool* arr = new bool[n+1];
    memset(arr, true, n+1 * sizeof(bool));

    Eratosthenes(n, arr);


    return 0;
}