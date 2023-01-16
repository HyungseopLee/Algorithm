#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int n, x;
    cin >> n >> x;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    
    int l = lower_bound(&arr[0], &arr[n], x) - &arr[0];
    int r = upper_bound(&arr[0], &arr[n], x) - &arr[0];

    if(r-l) {
        cout << r-l;
    } 
    else {
        cout << -1;
    }

    return 0;
}

/*

7 2
1 1 2 2 2 2 3
-> 4

7 5
1 1 2 2 2 2 3
-> -1


*/