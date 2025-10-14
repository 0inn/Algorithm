#include <string>
#include <vector>
#include <queue>

using namespace std;

int inter[1000001]; // 진입 차수
int outer[1000001]; // 진출 차수
vector<vector<int>> graph(1000001);
int donut = 0, stick = 0, eight=0;

int checkStartNode(vector<vector<int>> edges) {
    int startNode = -1;
    
    for(int i=0; i<edges.size(); i++) {
        // ex. [2, 3] > u:2, v:3
        int u = edges[i][0];
        int v = edges[i][1];
        inter[v]++;
        outer[u]++;
        graph[u].push_back(v);
        
        if(inter[u] == 0 && outer[u] >= 2) {
            startNode = u;
        }
        if(inter[v] == 0 && outer[v] >= 2) {
            startNode = v;
        }
    }
    
    return startNode;
}

void checkGraphType(int start) {
    queue<int> q;    
    q.push(start);
    bool is_visited = false;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        if(x==start && is_visited) {
            donut++;
            return;
        }
        
        if(graph[x].size() == 2) {
            eight++;
            return;
        }
            
        for(int i=0; i<graph[x].size(); i++) {
            q.push(graph[x][i]);
        }
        is_visited = true;
    }
    stick++;
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int start = checkStartNode(edges);
    answer.push_back(start); // 시작 정점
    
    for(auto node: graph[start]) {
        checkGraphType(node);
    }
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);

    return answer;
}