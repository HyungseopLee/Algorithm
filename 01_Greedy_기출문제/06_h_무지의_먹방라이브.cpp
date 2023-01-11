#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    
    vector<pair<int, int>> foods;
    int n = food_times.size();
    for (int i = 0; i < n; i++)
    {
        // (음식 시간, 음식 번호)  음식 번호는 1부터 시작하니까 i+1
        foods.push_back(make_pair(food_times[i], i+1));
    }
    // 음식 먹는 시간을 기준으로 오름차순 정렬
    sort(foods.begin(), foods.end());

    int prev_time = 0;
    for(vector<pair<int, int>>::iterator i = foods.begin() ; i != foods.end() ; i++, n--) {
        // 한꺼번에 줄어드는 시간
        long long spend_time = (long long)(i->first - prev_time) * n;
        if(spend_time == 0) {
            continue;
        }
        if(spend_time <= k) {
            k -= spend_time;
            prev_time = i->first;
        }
        else {
            k %= n;
            // 이떄는 음식 번호를 기준으로 재정렬해야 한다.
            sort(i, foods.end(), cmp);
            return (i + k)->second;
        }
    }
    // k가 충분해서 음식을 다 먹었는데도 시간이 남으면 -1 return
    return -1;
}

int main(void){

    vector<int> food_times = {3, 1, 2};
    int k = 5;

    cout << solution(food_times, k);

    return 0;
}

