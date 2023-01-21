#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    vector<int> house;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        house.push_back(input);
    }

    sort(house.begin(), house.end());

    // 중간값(median)을 출력
    cout << house[(n - 1) / 2] << '\n';
}