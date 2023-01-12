#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){

    string sort_s;
    string s;
    getline(cin, s);
    int sum = 0;

    for (auto i : s)
    {
        // 숫자라면
        if(i-'0' >= 0 && i-'0'<= 9){
            sum += i-'0';
        }
        else {
            sort_s.push_back(i);
        }
    }
    sort(sort_s.begin(), sort_s.end());

    cout << sort_s+ to_string(sum);

    return 0;
}

/*

K1KA5CB7

AJKDLSI412K4JSJ9D

*/