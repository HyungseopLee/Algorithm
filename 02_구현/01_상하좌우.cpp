#include <iostream>

using namespace std;

int main(void){

    int n;
    cin >> n;
    getchar();

    string plan;
    getline(cin, plan);
    auto it = remove(plan.begin(), plan.end(), ' ');
    plan.erase(it, plan.end());

    int current_x = 1, current_y = 1;

    for (int i = 0; i < plan.size(); i++)
    {
        if(plan[i] == 'L') {
            if(current_y != 1) {
                current_y -= 1;
            }
        }
        else if(plan[i] == 'R') {
            if(current_y != n) {
                current_y += 1;
            }
        }
        else if(plan[i] == 'U') {
            if(current_x != 1) {
                current_x -= 1;
            }
        }
        else if(plan[i] == 'D') {
            if(current_x != n) {
                current_x += 1;
            }
        }
    }
    
    cout << current_x << " " << current_y;

}