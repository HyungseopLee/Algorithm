// 문자열을 완전탐색하여
// 0이 연속적으로 있는 부분이 나타나는 횟수를 cnt1
// 1이 연속적으로 있는 부분이 나타나는 횟수를 cnt2
// min(cnt1, cnt2) 출력

#include <iostream>
#include <string>

using namespace std;

int main(void){

    string s;
    getline(cin, s);

    int cnt[2] = {0};
    char cur_char = s[0];
    cnt[cur_char - '0'] = 1;

    for(int i = 0 ; i < s.length() ; i++){
        if(cur_char != s[i]){
            cnt[s[i] - '0'] += 1;
            cur_char = s[i];
        }
    }
    cout << min(cnt[0], cnt[1]);
    
    return 0;
}

/*

0001100  --> 1

0101010001110 --> 4

*/