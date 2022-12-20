#include <iostream>

using namespace std;

int main(void){

    int n = 1260;
    int cnt;

    int cointTypes[4] = {500, 100, 50 , 10};

    for (int i = 0; i < 4; i++)
    {
        cnt += n / cointTypes[i];
        n %= cointTypes[i];
    }
    
    cout << cnt << endl;

    return 0;
}