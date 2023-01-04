#include <iostream>

using namespace std;

int findFamily(int* _family, int _data) {
    if(_family[_data] != _data) {
        _family[_data] = findFamily(_family, _family[_data]);
    }
    return _family[_data];
}

void beFamily(int* _family, int _v1, int _v2) {

    int _v1_family = findFamily(_family, _v1);
    int _v2_family = findFamily(_family, _v2);

    if(_v1_family < _v2_family) {
        _family[_v2] = _v1;
    }
    else {
        _family[_v1] = _v2;
    }
}

int main(void){

    int n, m;
    cin >> n >> m;

    int* team = new int[n+1];
    int* family = new int[n+1];

    for (int i = 0; i < n+1; i++)
    {
        family[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int teacher_input, t1, t2;
        cin >> teacher_input >> t1 >> t2;

        //  팀 합치기
        if(teacher_input == 0){
            beFamily(family, t1, t2);
        }
        // 같은 팀 여부 확인 (YES or NO)
        else if(teacher_input == 1) {
            if(findFamily(family, t1) != findFamily(family, t2)){
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
    
    

    return 0;
}

/*

7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

*/