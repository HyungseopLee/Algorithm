#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int n,k;
    cin >> n >> k;
    int sum = 0;

    int* arrA = new int[n];
    int* arrB = new int[n];

    // 배열 A 입력받고 오름차순 정렬
    for (int i = 0; i < n; i++)
    {
        int user_input;
        cin >> user_input;
        arrA[i] = user_input;
    }
    sort(arrA, arrA + n); 

    // 배열 B 입력받고 내림차순 정렬
    for (int i = 0; i < n; i++)
    {
        int user_input;
        cin >> user_input;
        arrB[i] = user_input;
    }
    sort(arrB, arrB + n);
    reverse(arrB, arrB + n);

    // 배열 A의 원소가 배열 B의 원소보다 작은 경우에만,
    // 배열 B의 큰 원소를 배열 A의 작은 원소에 대입한다
    for(int i = 0; i < k; i++)
    {
        arrA[i] = arrB[i];
        sum += arrA[i];
    }
    for (int i = k; i < n; i++)
    {
        sum += arrA[i];
    }
    
    cout << sum << endl;

    return 0;
}

/*

5 3
1 2 5 4 3
5 5 6 6 5

*/