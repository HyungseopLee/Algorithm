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

void merge(int _arr[], int _copy[], int left, int mid, int right) {
    int lidx = left;
    int lstart = left;
    int lend = mid;

    int ridx = mid + 1;
    int rstart = mid + 1;
    int rend = right;

    int cidx = left;

    while(1) {
        // lidx와 ridx가 범위를 넘어가면 종료
        if(lidx > lend && ridx > rend){
            break;
        }
        // lidx가 범위를 넘어가면 ridx만 copy 배열에 병합
        if(lidx > lend) {
            _copy[cidx] = _arr[ridx];
            cidx++;
            ridx++;
        }
        // ridx가 범위를 넘어가면 lidx만 copy 배열에 병합
        else if(ridx > rend) {
            _copy[cidx] = _arr[lidx];
            cidx++;
            lidx++;
        }
        // lidx, ridx 둘 다 범위 안에 있으면 더 작은 값부터 copy 배열에 병합
        else {
            if(_arr[lidx] < _arr[ridx]){
                _copy[cidx] = _arr[lidx];
                cidx++;
                lidx++;
            }
            else {
                _copy[cidx] = _arr[ridx];
                cidx++;
                ridx++;
            }
        }
    }

    // 병합하여 정렬된 리스트를 원본 배열에 복사
    for (int i = left; i <= right; i++)
    {
        _arr[i] = _copy[i];
    }
    
}

void mergeSort(int _arr[], int _copy[], int start, int end) {
    // 더이상 분할할 수 없으면 return
    if(start == end){
        return;
    }
    // 균등 분할
    mergeSort(_arr, _copy, start, (start+end)/2);
    mergeSort(_arr, _copy, (start+end)/2 + 1, end);

    // 병합
    merge(_arr, _copy, start, (start+end)/2 , end);
}

int main(void) {

    int arr[] = {5, 3, 8, 5, 9, 1, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* copy = new int(size);

    cout << "[before] : " ;
    showArr(arr, size);

    mergeSort(arr, copy, 0, size-1);
    
    cout << "[after] : ";
    showArr(arr, size);

    return 0;
}