//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int N;
char arr[7][7];
vector<p> teachers;
vector<int> comb;
string ans = "NO";

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/// 모든 학생이 감시 피할 수 있는지 여부 판단
bool checkIfPossible() {
    for(int i=0; i<teachers.size(); i++) {
        for(int dir=0; dir<4; dir++) {
            int nx = teachers[i].first + dx[dir];
            int ny = teachers[i].second + dy[dir];
            
            bool flag = true;
            while(flag) {
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) flag = false;
                if(arr[nx][ny] == 'T') flag = false;
                for(int o=0; o<3; o++) {
                    if(nx == comb[o]/N && ny == comb[o]%N) flag = false;
                }
                if(arr[nx][ny] == 'S') return false;
                nx += dx[dir]; ny +=dy[dir];
            }
        }
    }
    
    return true;
}

/// 장애물 세 개 고르기
void makeObstacles() {
    int len = N*N;
    vector<int> num(len), perm(len);
    
    for(int i=0; i<len; i++) num[i] = i;
    for(int i=len-3; i<len; i++) perm[i] = 1;
    
    do {
        comb.clear();
        
        for(int i=0; i<perm.size(); i++) {
            if(perm[i]==1 && arr[i/N][i%N] == 'X') {
                comb.push_back(num[i]);
            }
        }
        
        if(comb.size() == 3) {
            bool isPossible = checkIfPossible();
            if(isPossible) {
                ans = "YES";
                return;
            }
        }
    }while(next_permutation(perm.begin(), perm.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /// 입력
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'T') teachers.push_back({i, j});
        }
    }
    
    makeObstacles();
    
    cout << ans;
}
