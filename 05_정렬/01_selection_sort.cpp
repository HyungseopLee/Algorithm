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

void selectionSort(int _arr[], int _size) {
    for (int i = 0; i < _size - 1; i++)
    {
        int least = i;
        for (int j = i+1; j < _size; j++)
        {
            if(_arr[least] > _arr[j]){
                least = j;
            }
        }
        swap(_arr, least, i);
        cout << "step " << i+1 << " : ";
        showArr(_arr, _size);
    }
    
}

int main(void) {

    int arr[] = {5, 3, 8, 5, 9, 1, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "[before] : " ;
    showArr(arr, size);

    selectionSort(arr, size);
    
    cout << "[after] : ";
    showArr(arr, size);

    return 0;
}