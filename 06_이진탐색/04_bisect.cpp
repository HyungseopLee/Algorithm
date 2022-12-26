#include <iostream>
#include <vector>

using namespace std;

int main(void){

    vector <int> arr = {1, 2, 4, 4, 6};
    int x = 4;

    cout << lower_bound(arr.begin(), arr.end(), x) - arr.begin() << endl;
    cout << upper_bound(arr.begin(), arr.end(), x) - arr.begin() << endl;

    return 0;
}