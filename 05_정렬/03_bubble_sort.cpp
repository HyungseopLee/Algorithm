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

void bubbleSort(int _arr[], int _size) {
    
    for (int i = 0; i < _size - 1; i++)
    {
        for (int j = 0; j < _size - 1 - i; j++)
        {
            if(_arr[j] > _arr[j+1]) {
                swap(_arr, j, j+1);
            }
        }
        showArr(_arr, _size);
    }
    
    
}

int main(void) {

    int arr[] = {5, 3, 8, 5, 9, 1, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "[before] : " ;
    showArr(arr, size);

    bubbleSort(arr, size);
    
    cout << "[after] : ";
    showArr(arr, size);

    return 0;
}