#include <iostream>
#include <algorithm>

using namespace std;

int fix_point = -1;

void binarySearch(int* arr, int start, int end){
    if(start > end){
        return;
    }
    int mid = (start + end) / 2;
    if(arr[mid] == mid){
        fix_point = mid;
        return;
    }
    if(arr[mid] < mid) {
        binarySearch(arr, mid+1, end);
    }
    else{
        binarySearch(arr, start, mid-1);
    }
}

int main(void){

    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    binarySearch(arr, 0, n-1);

    if(fix_point == -1){
        cout << -1;
    }
    else {
        cout << fix_point;
    }

    return 0;
}

/*

5
-15 -6 1 3 7
-> 3

7
-15 -4 3 8 9 13 15
-> -1

*/