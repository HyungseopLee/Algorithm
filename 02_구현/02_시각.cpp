#include <iostream>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    bool flag = false;
    int cnt = 0;

    // n시 59분 59초에 3이 있는 경우의 수

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int k = 0; k < 60; k++)
            {
                if(i%10 == 3 || j/10 == 3 || j%10 == 3 || k/10 == 3 || k%10 == 3){
                    flag = true;
                }
                if(flag) {
                    cnt++;
                    flag = false;
                }
            }
        }
    }
    
    cout << cnt << endl;

    return 0;
}