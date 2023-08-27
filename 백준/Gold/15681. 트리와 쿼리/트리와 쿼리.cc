//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/22.
//

#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

struct Node {
    int parent = -1;
    vector<int> child;
};

int N, R, Q;
vector<int> graph[MAX];
Node tree[MAX];
int subtreeCnt[MAX];

void input() {
    cin >> N >> R >> Q;
    
    for(int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void makeTree(int curNode, int parent) {
    for(int i=0; i<graph[curNode].size(); i++) {
        int nxtNode = graph[curNode][i];
        if(nxtNode != parent) {
            tree[curNode].child.push_back(nxtNode);
            tree[nxtNode].parent = curNode;
            makeTree(nxtNode, curNode);
        } else {
            tree[nxtNode].parent = parent;
        }
    }
}

void countSubtreeNodes(int curNode) {
    subtreeCnt[curNode] = 1;
    for(int i=0; i<tree[curNode].child.size(); i++) {
        int child = tree[curNode].child[i];
        countSubtreeNodes(child);
        subtreeCnt[curNode] += subtreeCnt[child];
    }
}

void output() {
    while(Q--) {
        int root;
        cin >> root;
        cout << subtreeCnt[root] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    makeTree(R, -1);
    countSubtreeNodes(R);
    
    output();
}
