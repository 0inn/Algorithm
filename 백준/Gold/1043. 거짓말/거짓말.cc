//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M, C;
int group[51];
vector<int> party[51];
int ans = 0;

int find_group(int group[], int x) {
    if(x != group[x]) {
        return group[x] = find_group(group, group[x]);
    } else {
        return group[x];
    }
}

void merge_person(int group[], int x, int y) {
    int px = find_group(group, group[x]);
    int py = find_group(group, group[y]);
    
    if(px != py) {
        if(px < py)
            group[py] = group[px];
        else
            group[px] = group[py];
    }
}

void input() {
    cin >> N >> M >> C;
    
    for(int i=0; i<=N; i++) {
        group[i] = i;
    }
    
    while(C--) {
        int num;
        cin >> num;
        group[num] = 0;
    }
    
    for(int i=0; i<M; i++) {
        int cnt, first;
        cin >> cnt >> first;
        
        party[i].push_back(first);
        
        for(int j=1; j<cnt; j++) {
            int num;
            cin >> num;
            party[i].push_back(num);
            merge_person(group, first, num);
        }
    }
}

void solution() {
    ans = M;
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<party[i].size(); j++) {
            if(find_group(group, group[party[i][j]]) == 0) {
                ans--;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solution();
    cout << ans;
}
