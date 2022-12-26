#include <iostream>

using namespace std;

// 임의로 설정한 절단기 길이 : mid = (start + end) / 2
// (mid만큼 자르고 남은 떡들의 합) < m 인 경우, mid+1 다시 탐색
// (mid만큼 자르고 남은 떡들의 함) > m 이 되는 경우, mid-1 다시 탐색 (단, 가장 최근의 mid값을 저장)
// 위 과정이 start>end 될 때까지
int binarySearch(int _arr[], int start, int end, int _n, int _m){
    int ret = 0;
    while(start <= end) {
        int sum = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < _n; i++)
        {
            int cut_len = _arr[i] - mid;
            // 자른 떡의 길이가 양수라면, sum에 더한다
            if(cut_len > 0) { 
                sum += _arr[i] - mid;
            }
            // 자른 떡의 길이가 음수 == 절단기가 길어서 떡이 잘라지지 않음
            else sum += 0;
            
        }
        // 떡이 사용자가 요구한 것보다 충분하면, 절단기 길이를 늘림 == 떡을 덜 자름(왼쪽 부분 탐색)
        if(sum >= _m){
            ret = mid; // 최적화된 절단기 길이 갱신
            start = mid+1;
        }
        // 떡이 모자라면, 절단기 길이를 줄임==떡을 더 많이 자름(오른쪽 부분 탐색)
        else {
            end = mid-1;
        }
    }
    return ret;
}

int main(void){

    // 자를 떡의 개수(N)과 사용자가 필요한 떡의 양(M)을 입력받기
    int n,m; 
    cin >> n >> m;

    // 떡 개별 높이 입력 받기
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int user_input;
        cin >> user_input;
        arr[i] = user_input;
    }

    // 이진 탐색의 초기 탐색 범위를 start = 0, end = 떡 개별 높이의 최대값
    int start = 0;
    int end = *max_element(arr, arr+n);
    
    // 이진 탐색 시작
    int max_h = binarySearch(arr, start, end, n, m);
    cout << max_h << endl;

    return 0;
}

/*

4 6
19 15 10 17

*/