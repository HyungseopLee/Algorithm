#include <iostream>

using namespace std;

int GCD(int _a, int _b) {
    if (_a % _b == 0){
        return _b;
    }
    else {
        return GCD(_b, _a % _b);
    }
}

int main(void){

    int a = 192, b = 162;

    cout << GCD(a,b) << endl;

    return 0;
}