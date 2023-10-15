#include <queue>
#include <vector>

using namespace std;

struct Camera {
    int s, e;
};

struct cmp {
    bool operator()(Camera c1, Camera c2) {
        return c1.s > c2.s;
    }
};

priority_queue<Camera, vector<Camera>, cmp> pq;
int idx = -300001, ans = 0;

int solution(vector<vector<int>> routes) {
    for(int i=0; i<routes.size(); i++) {
        int x = routes[i][0], y = routes[i][1];
        pq.push(Camera{ x, y });
    }
    
    while(!pq.empty()) {
        Camera cur = pq.top();
        pq.pop();
        
        if(idx < cur.s) {
            idx = cur.e;
            ans++;
        } else if(idx >= cur.e) {
            idx = cur.e;
        }
    }
    
    return ans;
}