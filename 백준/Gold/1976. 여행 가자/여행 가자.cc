//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/12.
//

#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

int N, M;
int arr[MAX][MAX];
vector<int> plan;

void input() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
            if(i != j && arr[i][j] == 0) arr[i][j] = MAX;
        }
    }
    
    for(int i=0, m; i<M; i++) {
        cin >> m;
        plan.push_back(m);
    }
}

void calculate_dist() {
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                int dist = arr[i][k] + arr[k][j];
                if(arr[i][j] > dist) {
                    arr[i][j] = dist;
                }
            }
        }
    }
    
    for(int i=1; i<plan.size(); i++) {
        int from = plan[i-1], to = plan[i];
        if(arr[from][to] == MAX) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    calculate_dist();
}
