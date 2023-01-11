#include <iostream>
#include <vector>

using namespace std;

int main(void){

    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    int cur_cnt = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        // 모험가 포함시키기
        cur_cnt += 1;
        // 포함된 모험가들이 현재 공포도보다 크거나 같으면 그룹 결성
        if(cur_cnt >= arr[i]){
            result += 1;
            cur_cnt = 0; 
        }
    }
    
    cout << result;

    return 0;
}

/*

(1)
5
2 3 1 2 2

(2)
8
5 5 5 3 4 1 2

*/