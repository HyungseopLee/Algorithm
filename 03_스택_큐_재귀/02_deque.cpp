#include <iostream>
#include <deque>

using namespace std;

int main(void){

    deque <int> q;

    q.push_back(5);
    q.push_back(2);
    q.push_back(3);
    q.push_back(7);

    q.pop_front();

    q.push_back(1);
    q.push_back(4);

    q.pop_front();

    while (!q.empty())
    {
        cout << *(q.begin()) << ' '; // 가장 먼저 들어온 데이터 출력
        q.pop_front(); // 가장 먼저 들어온 데이터 삭제
    }
    

    return 0;
}