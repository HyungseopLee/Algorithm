#include <iostream>

using namespace std;

int main(void){

    int n;
    cin >> n;
    int* warehouse = new int[n];
    int* dp_table = new int[n] {0};

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        warehouse[i] = k;
    }

    dp_table[0] = warehouse[0];
    dp_table[1] = max(warehouse[0], warehouse[1]);

    for (int i = 2; i < n; i++)
    {
        dp_table[i] = max(dp_table[i-1], dp_table[i-2] + warehouse[i]);
    }

    cout << dp_table[n-1] << endl;
    
    return 0;
}

/*

4
1 3 1 5

*/