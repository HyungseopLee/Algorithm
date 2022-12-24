#include <iostream>
#define HEAP_SIZE 100

using namespace std;

int heap[HEAP_SIZE];
int hsz = 0;

void swap(int _heap[], int a, int b){
    int temp = _heap[a];
    _heap[a] = _heap[b];
    _heap[b] = temp;
}

void enheap(int _data){
    if(hsz == HEAP_SIZE - 1){
        return;
    }
    hsz++;
    heap[hsz] = _data;

    int me = hsz;
    int parent = me / 2;

    // 방금 들어온 data가 부모 index의 data보다 커야 한다.
    // heap을 재정렬
    while(1){
        // 루트 노드까지 왔으면 멈춘다
        if(me == 1){
            return;
        }
        // 부모 data가 더 크면 멈춘다
        if(heap[parent] >= heap[me]) {
            return;
        }
        // 자식 data가 더 크면 부모 data와 swap
        else {
            swap(heap, me, parent);

            me = parent; 
            parent = me / 2;
        }
    }
}

int findReplacer(int _me) {
    int left_child = 2*(_me);
    int right_child = 2*(_me) + 1;

    // 자식 노드가 deheap()하여 제거된 노드라면 == 자식 노드가 없다면
    if(hsz < left_child) {
        return -1;
    }
    // 왼쪽 자식 노드만 존재한다면
    if(hsz < right_child) {
        return left_child;
    }
    // 왼쪽 자식 노드와 오른쪽 자식 노드가 둘 다 존재한다면
    else {
        // 둘 중 더 큰 값을 반환해준다
        if(heap[left_child] > heap[right_child]){
            return left_child;
        }
        return right_child;
    }

}

int deheap() {
    if(hsz == 0){
        return -999;
    }

    // 루트 노드의 data를 반환해준다.
    int ret = heap[1]; 

    // ret을 return하기 전에 힙 재정렬
    // 임시적으로 가장 마지막 노드의 값을 루트 노드에 넣는다.
    heap[1] = heap[hsz]; 
    hsz--;
    int me = 1;
    // 임시적으로 루트가 된 data가 들어갈 자리를 찾으며 재정렬한다.
    while(1){
        // 임시적 루트가 된 me를 대신하여 올라올 대상자 선택. 
        // (자식 노드 중 값이 큰 것을 찾아온다)
        int replacer = findReplacer(me);

        // 자식 노드가 없다면 멈춤
        if(replacer == -1){
            return ret;
        }
        // 자식 노드보다 me가 더 크다면 재정렬할 필요없으니 멈춤
        if(heap[me] > heap[replacer]) {
            return ret;
        }
        // 자식 노드가 me보다 크다면, 자식과 me의 위치를 바꿔준다
        else {
            swap(heap, me, replacer);

            me = replacer;
        }
    }
}

int main(void){

    enheap(-1);
    enheap(1);
    enheap(-2);
    enheap(2);
    enheap(0);
    enheap(3);
    enheap(4);
    enheap(5);

    while(1){
        int res = deheap();
        if(res == -999){
            break;
        }
        cout << res << " ";
    }

    return 0;
}