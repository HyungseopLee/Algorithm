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

void shellSort(int _arr[], int _size) {
    
    int i, j, k, gap;

    for(gap = _size/2 ; gap > 0; gap/=2){
        for(i = 0 ; i < gap ; i++){
            for(j = i + gap ; j < _size ; j+=gap){
                int me = _arr[j];
                for(k = j - gap ; k>=0 ; k-=gap){
                    if(me < _arr[k]) {
                        _arr[k + gap] = _arr[k];
                    }
                    else {
                        break;
                    }
                }
                _arr[k+gap] = me;
                showArr(_arr, _size);
            }
        }
    }
    
}

int main(void) {

    int arr[] = {5, 3, 8, 5, 9, 1, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "[before] : " ;
    showArr(arr, size);

    shellSort(arr, size);
    
    cout << "[after] : ";
    showArr(arr, size);

    return 0;
}