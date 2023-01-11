#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int n, m, k;
    int first_num, second_num;
    int cnt = 0, sum = 0;

    cin >> n;
    cin >> m;
    cin >> k;

    int* arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(&arr[0], &arr[n-1]);
    first_num = arr[n-1];
    second_num = arr[n-2];
    
    for (int i = 0; i < m; i++)
    {
        if(cnt == k) {
            cnt = 0;
            sum += second_num;
        }
        else {
            cnt++;
            sum += first_num;
        }
    }
    
    cout << sum;

    return 0;
}

/*

5 8 3
2 4 5 4 6

*/