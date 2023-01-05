#include <iostream>

using namespace std;

bool isPrimeNum(int x) {
    for (int i = 2; i <= x-1; i++)
    {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void){

    cout << boolalpha;
    cout << isPrimeNum(4) << endl;
    cout << isPrimeNum(7) << endl;

    return 0;
}