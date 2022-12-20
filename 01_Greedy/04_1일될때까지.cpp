#include <iostream>

using namespace std;

int main(void){

    int n, k;
    cin >> n;
    cin >> k;

    int result = 0;

    while(1) {
        if(n == 1) {
            break;
        }
        if(n%k == 0) {
            n /= k;
            result += 1;
        }
        else {
            n -= 1;
            result += 1;
        }
    }
    cout << result;

    return 0;
}