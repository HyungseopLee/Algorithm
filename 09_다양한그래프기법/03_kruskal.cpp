#include <iostream>
#include <vector>

using namespace std;

int find_parent(int* _parent, int _data) {
    if(_parent[_data] != _data) {
        _parent[_data] = find_parent(_parent, _parent[_data]);
    }
    return _parent[_data];
}

void union_parent(int* _parent, int _v1, int _v2) {
    int v1_parent = find_parent(_parent, _v1);
    int v2_parent = find_parent(_parent, _v2);
    if(v1_parent < v2_parent) {
        _parent[v2_parent] = v1_parent;
    }
    else {
        _parent[v1_parent] = v2_parent;
    }
}

int main(void){


    int v, e;
    int* parent = new int[v+1];

    vector<pair<int, pair<int, int>>> edges; // cost, {v1, v2}
    int res = 0;

    cin >> v >> e;

    for (int i = 0; i < v+1; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < e; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        edges.push_back({cost, {v1, v2}});
    }
    // 간선 오름차순 정렬
    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].first;
        int v1 = edges[i].second.first;
        int v2 = edges[i].second.second;
        if(find_parent(parent, v1) == find_parent(parent, v2)){
            continue;
        }
        else {
            union_parent(parent, v1, v2);
            cout << v1 << " --- " << v2 << endl;
            res += cost;
        }
    }

    cout << "total cost : " << res << endl;

    return 0;
}

/*

7 9
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25

*/