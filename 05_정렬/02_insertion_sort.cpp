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

void insertionSort(int _arr[], int _size) {
    
    int i, j;

    for (i = 1; i < _size; i++)
    {
        int me = _arr[i];
        for (j = i-1; j >= 0; j--)
        {
            if(me < _arr[j]) {
                _arr[j+1] = _arr[j];
            }
            else {
                break;
            }
        }
        _arr[j+1] = me; 
        showArr(_arr, _size);
    }
    
    
}

int main(void) {

    int arr[] = {5, 3, 8, 5, 9, 1, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "[before] : " ;
    showArr(arr, size);

    insertionSort(arr, size);
    
    cout << "[after] : ";
    showArr(arr, size);

    return 0;
}