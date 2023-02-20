#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long>* matrix = new vector<long long>[n+1];
    vector<long long> sum;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long input;
            cin >> input;
            matrix[i].push_back(input);
        }
        sum.push_back(0);
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[i] += matrix[i][j];
            if(sum[i] >= k){
                cout << i+1 << ' ' << j+1;
                return 0;
            }
        }
        
    }
    

    return 0;
}