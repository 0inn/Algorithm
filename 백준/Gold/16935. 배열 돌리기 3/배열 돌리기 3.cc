//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> arr(101, vector<int>(101, 0));
vector<vector<int>> new_arr(101, vector<int>(101, 0));

void change_up_down() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            new_arr[i][j] = arr[N-i-1][j];
        }
    }
}

void change_left_right() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            new_arr[i][j] = arr[i][M-j-1];
        }
    }
}

void rotate_right() {
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            new_arr[i][N-j-1] = arr[j][i];
        }
    }
}

void rotate_left() {
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            new_arr[i][j] = arr[j][M-i-1];
        }
    }
}

void cal_five() {
    int n = N/2;
    int m = M/2;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            new_arr[i][j] = arr[i+n][j]; // 1 <- 4
            new_arr[i][j+m] = arr[i][j]; // 2 <- 1
            new_arr[i+n][j+m] = arr[i][j+m]; // 3 <- 2
            new_arr[i+n][j] = arr[i+n][j+m]; // 4 <- 3
        }
    }
}

void cal_six() {
    int n = N/2;
    int m = M/2;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            new_arr[i][j] = arr[i][j+m]; // 1 <- 2
            new_arr[i][j+m] = arr[i+n][j+m]; // 2 <- 3
            new_arr[i+n][j+m] = arr[i+n][j]; // 3 <- 4
            new_arr[i+n][j] = arr[i][j]; // 4 <- 1
        }
    }
}

void input() {
    cin >> N >> M >> R;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    
    while(R--) {
        int op;
        cin >> op;
        
        switch(op) {
            case 1:
                change_up_down();
                break;
            case 2:
                change_left_right();
                break;
            case 3:
                rotate_right();
                swap(N, M);
                break;
            case 4:
                rotate_left();
                swap(N, M);
                break;
            case 5:
                cal_five();
                break;
            case 6:
                cal_six();
                break;
        }
        arr = new_arr;
    }
}

void output() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << new_arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    output();
}
