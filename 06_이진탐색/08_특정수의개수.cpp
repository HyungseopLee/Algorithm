// 직접 이진 탐색 구현

#include <iostream>

using namespace std;

int last = -1;

int findFirstX(int _arr[], int start, int end, int _x){
    int mid = (start + end) / 2;

    if(start > end) {
        return last;
    }
    // 찾는 값이 나오면, last값 갱신, return하지 않고 더 적은 index를 찾는다)
    if(_arr[mid] == _x){
        last = mid;
        return findFirstX(_arr, start, mid-1, _x);
    }
    // 찾는 값이 더 크면
    else if(_arr[mid] < _x) {
        return findFirstX(_arr, mid+1, end, _x);
    }
    // 찾는 값이 더 작으면
    else if(_arr[mid] > _x) {
        return findFirstX(_arr, start, mid-1, _x);
    }
}
int findSeondX(int _arr[], int start, int end, int _x){
    int mid = (start + end) / 2;

    if(start > end) {
        return last;
    }
    // 찾는 값이 나오면, last값 갱신, return하지 않고 더 큰 index를 찾는다)
    if(_arr[mid] == _x){
        last = mid;
        return findSeondX(_arr, mid+1, end, _x);
    }
    // 찾는 값이 더 크면
    else if(_arr[mid] < _x) {
        return findSeondX(_arr, mid+1, end, _x);
    }
    // 찾는 값이 더 작으면
    else if(_arr[mid] > _x) {
        return findSeondX(_arr, start, mid-1, _x);
    }
}

int main(void){

    int n, x;

    cin >> n >> x;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int user_input;
        cin >> user_input;
        arr[i] = user_input;
    }
    
    last = -1;
    int firstX = findFirstX(arr, 0, n-1, x);
    last = -1;
    int secondX = findSeondX(arr, 0, n-1, x);

    if(firstX == -1 || secondX == -1){
        cout << -1 << endl;
    }
    else {
        cout << secondX - firstX + 1 << endl;
    }

    return 0;
}

/*

7 2
1 1 2 2 2 2 3

*/