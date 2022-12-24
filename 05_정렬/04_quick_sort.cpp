#include <iostream>

using namespace std;

void showArr(int _arr[], int _size) {
    for (int i = 0; i < _size; i++)
    {
        cout << _arr[i] << " ";
    }
    cout << endl;
    
}

void swap(int _arr[], int a, int b){
    int temp = _arr[a];
    _arr[a] = _arr[b];
    _arr[b] = temp;
}

void quickSort(int _arr[], int start, int end, int _size) {
    int pivot = start;
    int low = start + 1;
    int high = end;

    if(start >= end){
        return;
    }

    while(low <= high) {
        // pivot보다 low index의 값이 더 크면 break
        while((_arr[pivot] >= _arr[low]) && (low <= end)) { 
            low++;
        }
        // pivot보다 high index의 값이 더 작으면 break
        while((_arr[pivot] <= _arr[high]) && (high >= start + 1)) { 
            high--;
        }
        if(low <= high){
            swap(_arr, low, high);
        }
        cout << "pivot : " << _arr[pivot] << "   ";
        showArr(_arr, _size);
    }
    swap(_arr, pivot, high);

    cout << "pivot : " << _arr[high] << " : ";
    showArr(_arr, _size);

    quickSort(_arr, start, high - 1, _size);
    quickSort(_arr, high+1, end, _size);
}

int main(void) {

    int arr[] = {5, 3, 8, 5, 9, 1, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "[before] : " ;
    showArr(arr, size);

    quickSort(arr, 0, size-1, size);
    
    cout << "[after] : ";
    showArr(arr, size);

    return 0;
}