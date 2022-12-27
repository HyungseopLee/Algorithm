#include <iostream>

using namespace std;

int main(void){

    int n;
    cin >> n;

    int* dp_table = new int[n+1]{0};

    dp_table[1] = 1;
    dp_table[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        dp_table[i] = (dp_table[i-1] + 2*dp_table[i-2]) % 796796;
    }
    cout << dp_table[n] << endl;

    return 0;
}

/*

3

*/