#include <iostream>

int binarySearch(int _arr[], int start, int end, int _target){
    int mid = (start + end) / 2;
    if(start > end){
        return -999;
    }
    // 찾은 경우
    if(_arr[mid] == _target){
        return mid;
    }
    // mid보다 큰 경우
    else if(_arr[mid] < _target) { 
        return binarySearch(_arr, mid+1, end, _target);
    }
    // mid보다 작은 경우
    else { 
        return binarySearch(_arr, start, mid-1, _target);
    }
}

using namespace std;

int main(void){

    int n, target;
    cin >> n >> target;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        int user_input;
        cin >> user_input;
        arr[i] = user_input;
    }

    int index = binarySearch(arr, 0, n-1, target);
    if(index) {
        cout << target << "은 " << index << "번 인덱스에 있습니다\n";
    }
    else {
        cout << target << "은 존재하지 않습니다.\n";
    }

    return 0;
}