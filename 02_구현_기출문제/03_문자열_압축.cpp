#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;

    // len/2 보다 큰 단위로 자르지 못하기 때문에 len/2까지만 실행
    for (int unit = 1; unit <= len/2; unit++)
    {
        string final_str = "";
        string cur_unit_str = s.substr(0, unit); // 0부터 0+unit 직전까지 자르기 -> 제일 앞부터 정해진 길이만큼 잘라야 한다는 문제 조건이 있기 때문에 
        int cnt = 1; // 반복되는 unit 개수 

        for (int i = unit; i < len; i += unit)
        {
            string next_unit_str = s.substr(i, unit);
            // unit=2 기준, s[0]s[1]과 s[2]s[3]이 같다면
            if(cur_unit_str == next_unit_str) {
                cnt += 1;
            }
            // unit=2 기준, s[0]s[1]과 s[2]s[3]이 다르다면 
            else {
                // cur_unit이 반복된 개수가 1개 이하이면 1cur_unit 으로 하면 더 길어지니까 2이상인 경우에만 2cur_unit으로 한다.
                final_str += (cnt >= 2) ? to_string(cnt)+cur_unit_str : cur_unit_str;
                cur_unit_str = next_unit_str;
                cnt = 1;
            }
        }
        // for문에서 처리되지 못하고 남은 문자들을 처리해준다.
        final_str += (cnt >= 2) ? to_string(cnt)+cur_unit_str : cur_unit_str;
        answer = (answer < final_str.length() ? answer : final_str.length());
    }
    
    return answer;
}

int main(void){

    cout << solution("aabbaccc") << endl;
    cout << solution("xababcdcdababcdcd") << endl;

    return 0;
}

/*

abcabcabcabcdededededede
-> 14

xababcdcdababcdcd
17

*/