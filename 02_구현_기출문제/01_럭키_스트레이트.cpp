#include <iostream>
#include <string>

using namespace std;

int main(void){

    string n;
    getline(cin, n);

    int left = 0, right = 0;;
    for (int i = 0; i < n.size()/2; i++)
    {
        left += n[i] - '0';
    }
    for (int i = n.size()/2; i < n.size(); i++)
    {
        right += n[i] - '0';
    }
    if(left == right){
        cout << "LUCKY";
    }
    else {
        cout << "READY";
    }

    return 0;
}