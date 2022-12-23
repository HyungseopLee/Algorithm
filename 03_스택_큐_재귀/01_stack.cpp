#include <iostream>
#include <stack>

using namespace std;

int main(void){

    stack <int> s;

    s.push(5);
    s.push(2);
    s.push(3);
    s.push(7);

    s.pop();

    s.push(1);
    s.push(4);

    s.pop();

    while (!s.empty())
    {
        cout << s.top() << ' '; // top에 있는 원소값 출력
        s.pop(); // 삭제
    }
    

    return 0;
}