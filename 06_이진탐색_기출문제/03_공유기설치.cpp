#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    vector<long long> house;
    int n, c;

    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        house.push_back(input);
    }
    // 1. 주어진 집들의 좌표 정렬
    sort(house.begin(), house.end());

    // 2. 최소거리 : 1, 최대 거리 : 끝집-첫집
    int start = 1;
    int end = house[n-1] - house[0];
    int result = 0;

    // 3. 집들 사이의 거리를 기준으로 이분 탐색
    while(start <= end) {
        int gap = (start + end) / 2;
        int cnt = 1; // 첫번째 집은 이미 설치했다고 가정.
        int last_house = house[0];
        for (int i = 1; i < n; i++)
        {
            int diff = house[i] - last_house;
            if(diff >= gap){
                cnt++;
                last_house = house[i];
            }
        }
        // 공유기 제한 횟수보다 더 많이 설치 된 경우, 공유기 설치 하는 gap을 더 늘린다
        if(cnt >= c){
            result = max(result, gap);
            start = gap + 1;
        }
        // 공유기를 모두 설치 못한 경우, gap을 줄인다
        else{
            end = gap - 1;
        }
    }
        
    cout << result;

    return 0;
}

/*

5 3
1
2
8
4
9

*/