#include <iostream>
#include <vector>
using namespace std;

// 트리
// 리프 노드 = 자식 개수가 0인 노드
// 노드 중 하나를 제거 후 리프 노드의 개수 구하기

int N, R;
vector <int> node[51];
int root;
int answer;

void check(int pivot) {
    
    if(pivot == R) // 지워진 노드라면
        return;
    
    int child = 0;
    
    for(int i = 0; i<node[pivot].size(); i++) {
        if(node[pivot][i] == R) continue;
        check(node[pivot][i]);
        child++;
    }
    
    if(child == 0) answer++;
}

int main() {
    
    cin >> N;
    
    int parent;
    for(int i = 0; i<N; i++) {
        
        cin >> parent;
        
        if(parent == -1)
        {
            root = i;
            continue;
        }
        
        node[parent].push_back(i);
    }
    
    cin >> R;
    node[R].clear();
    check(root);
    cout << answer;
    
    return 0;
}
