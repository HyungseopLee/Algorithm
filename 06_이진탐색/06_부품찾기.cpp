#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n, m;
    vector<int> nArr;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nArr.push_back(temp);
    }
    // 이진 탐색을 위해 정렬
    sort(nArr.begin(), nArr.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        // 있으면?
        if(binary_search(nArr.begin(), nArr.end(), temp)) {
            cout << "yes ";
        }  
        // 없으면?
        else {
            cout << "no ";
        }
    }
    


    return 0;
}

/*

5
8 3 7 9 2
3
5 7 9

*/