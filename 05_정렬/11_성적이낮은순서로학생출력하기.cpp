#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student{

public :
    string name;
    int score;
    Student(string _name, int _score) : name(_name), score(_score) {}
};

bool compare(Student& a, Student& b){
    return a.score < b.score;
}

int main(void){

    int n;
    cin >> n;

    vector<Student> stus;

    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        
        cin >> name;
        cin >> score;

        Student temp(name, score);
        stus.push_back(temp);
    }

    sort(stus.begin(), stus.end(), compare);

    for (auto& i : stus)
    {
        cout << i.name << " ";
    }
    

    return 0;
}

/*

2
홍길동 95
이순신 77

*/