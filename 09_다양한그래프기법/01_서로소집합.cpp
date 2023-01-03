#include <iostream>

using namespace std;

int findParent(int data, int* parent) {
    if(parent[data] != data) {
        parent[data] = findParent(parent[data], parent);
    }
    return parent[data];
}

void unionParent(int v1, int v2, int* parent) {
    int v1_parent = findParent(v1, parent);
    int v2_parent = findParent(v2, parent);
    if(v1_parent < v2_parent) {
        parent[v2] =  v1;
    }
    else {
        parent[v1] =  v2;
    }
}

int main(void){

    int n, e;
    cin >> n >> e;

    int* parent = new int[n+1];

    for (int i = 0; i < n+1; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        unionParent(v1, v2, parent);
    }
    
    cout << "[각 원소가 속한 집합] ";
    for (int i = 1; i <= n; i++)
    {
        cout << findParent(i, parent) << " ";
    }
    cout << "\n[부모 테이블] ";
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << " ";
    }
    

    return 0;
}