#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101][2]; // [x좌표][y좌표][기둥(0), 보(1)]
int N;

bool add_item(int x, int y, int isRow) {
    if(isRow) { // 보 설치
        if(y > 0 && arr[x][y-1][0]) return true; // 왼쪽 아래 기둥
        if(x < N && y > 0 && arr[x+1][y-1][0]) return true; // 오른쪽 아래 기둥
        if(x > 0 && x < N && arr[x-1][y][1] && arr[x+1][y][1]) return true; // 양쪽 보
    } else {    // 기둥 설치
        if(y == 0) return true; // 바닥위
        if(x > 0 && arr[x-1][y][1]) return true; // 보의 오른쪽 끝
        if(y < N && arr[x][y][1]) return true; // 보의 왼쪽 끝
        if(y > 0 && arr[x][y-1][0]) return true; // 다른 기둥 위
    }
    return false;
}

bool remove_item(int x, int y, int isRow) {
    arr[x][y][isRow] = 0;
    
    if(isRow) {  // 보 삭제
        // 양쪽 위에 기둥이 있을 때, 설치 가능 여부
        if(arr[x][y][0] && !add_item(x, y, 0)) return false;
        if(x < N && arr[x+1][y][0] && !add_item(x+1, y, 0)) return false;
        // 다른 보와 연결되어 있을 때, 설치 가능 여부
        if(x > 0 && arr[x-1][y][1] && !add_item(x-1, y, 1)) return false;
        if(x < N && arr[x+1][y][1] && !add_item(x+1, y, 1)) return false;
    } else {    // 기둥 삭제
        // 위에 기둥이 있을 때, 설치 가능 여부
        if(y < N && arr[x][y+1][0] && !add_item(x, y+1, 0)) return false;
        // 위에 보가 있을 때, 설치 가능 여부
        if(y < N && arr[x][y+1][1] && !add_item(x, y+1, 1)) return false;
        if(x > 0 && y < N && arr[x-1][y+1][1] && !add_item(x-1, y+1, 1)) return false;
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
    vector<vector<int>> answer;
    
    for(auto info: build_frame) {
        int x = info[0], y = info[1], isRow = info[2], isAdd = info[3];
        
        if(isAdd) {
            if(add_item(x, y, isRow)) arr[x][y][isRow] = 1;
        } else {
            if(!remove_item(x, y, isRow)) arr[x][y][isRow] = 1;
        }
    }

    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=n; ++j) {
            if(arr[i][j][0]) answer.push_back({i, j, 0});
            if(arr[i][j][1]) answer.push_back({i, j, 1});
        }
    }
        
    return answer;
}