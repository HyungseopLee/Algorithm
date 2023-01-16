#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class STU{

public :
    STU(string name, int kor, int eng, int math) : name(name), kor(kor), eng(eng), math(math) {}
    string name;
    int kor, eng, math;
};

int n;

bool cmp(STU& a, STU& b){
    // 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로
     if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) {
        return a.name < b.name;
    }
    // 그렇지 않고 국어와 영어 점수만 같은 경우, 수학 점수가 감소하는 순서로
    if (a.kor == b.kor && a.eng == b.eng) {
        return a.math > b.math;
    }
    // 그렇지 않고 국어 점수만 같은 경우, 영어 점수가 증가하는 순서로
    if (a.kor == b.kor) {
        return a.eng < b.eng;
    }
    // 나머지 경우, 국어 점수가 감소하는 순서로
    return a.kor > b.kor;
}

int main(void){

    cin >> n;

    vector<STU> stus;

    for (int i = 0; i < n; i++)
    {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        STU temp(name, kor, eng, math);
        stus.push_back(temp);
    }

    sort(stus.begin(), stus.end(), cmp);
    
    for (auto i : stus)
    {
        cout << i.name << "\n";
    }
    

    return 0;
}

/*

12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90

->

Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan

*/