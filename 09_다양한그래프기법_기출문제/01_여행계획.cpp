#include <iostream>

// 그래프끼리 합집합을 하여 같은 집합 안에 있는지 확인한다.
// 2 3 4 3 이 들어왔으면, 2 3 4의 parent가 같으면 yes 아니면 no

using namespace std;

int* parent;

int findParent(int data){
    if(parent[data] != data) {
        parent[data] = findParent(parent[data]);
    }
    return parent[data];
}

void unionParent(int a, int b){
    int pa = findParent(a);
    int pb = findParent(b);

    if(pa < pb){
        parent[b] = pa;
    }
    else{
        parent[a] = pb;
    }
}

int main(void){

    int n, m;
    cin >> n >> m;

    parent = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            int v;
            cin >> v;
            if(v == 1){
                unionParent(i, j);
            }
        }
        
    }
    // 여행 계획 입력받기
    int* plan = new int[m+1];
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        plan[i] = p;
    }
    // 여행할 곳의 parent가 모두 같아야 여행 계획이 가능하다.
    for (int i = 0; i < m-1; i++)
    {
        if(findParent(plan[i]) != findParent(plan[i+1])){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    

    return 0;
}

/*

5 4
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0
2 3 4 3

*/