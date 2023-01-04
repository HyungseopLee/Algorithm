#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findFamily(int _family[], int _data){
    if(_family[_data] != _data) {
        _family[_data] = findFamily(_family, _family[_data]);
    }

    return _family[_data];
}
void beFamily(int _family[], int _h1, int _h2){
    int _h1_family = findFamily(_family, _h1);
    int _h2_family = findFamily(_family, _h2);

    if(_h1_family < _h2_family) {
        _family[_h2_family] = _h1_family;
    }
    else {
        _family[_h1_family] = _h2_family;
    }
}

int kruskal(int _family[], vector<pair<int, pair<int, int>>>& _edges){

    int last_cost, result = 0;
    for(int i = 0 ; i < _edges.size() ; i++) {
        int cost = _edges[i].first;
        int h1 = _edges[i].second.first;
        int h2 = _edges[i].second.second;

        // cycle 발생하면, pass
        if(findFamily(_family, h1) == findFamily(_family, h2)) {
            continue;
        }
        else {
            beFamily(_family, h1, h2);
            result += cost;
            last_cost = cost;
        }
    }
    // 가장 큰 비용을 빼줘서 두 마을로 분할한다.
    return result - last_cost; 
}

int main(void){

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    int* family = new int[n+1];
    for (int i = 1; i <= n; i++)
    {
        family[i] = i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int h1, h2, cost;
        cin >> h1 >> h2 >> cost;
        edges.push_back({cost, {h1, h2}});
    }
    sort(edges.begin(), edges.end());   

    cout << kruskal(family, edges);
    

    return 0;
}

/*

7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4

*/