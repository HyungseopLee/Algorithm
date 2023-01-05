#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void printPrimeNums(bool* primes, int m, int n){
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(primes[i]){
            int j = 2;
            while(1){
                if(i * j > n){
                    break;
                }
                primes[i * j] = false;
                j += 1;
            }
        }
    }
    for (int i = m; i <= n; i++)
    {
        if(primes[i]){
            cout << i << '\n';
            // endl은 출력 버퍼를 지워야 해서 더 느리다.
            // endl을 사용했을 때 시간 초과를 받았다.
        }
    }
}

int main(void) {

    int m, n;
    cin >> m >> n;
    
    bool* prime = new bool[n+1];
    memset(prime, true, sizeof(bool) * (n+1));
    prime[1] = false;

    printPrimeNums(prime, m, n);

    return 0;
}

/*
3 16
*/