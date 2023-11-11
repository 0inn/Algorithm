//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000000001

using namespace std;

struct Info {
    int h, cnt;
};

int N;
vector<Info> B;

void input() {
    cin >> N;
    
    int h;
    for(int i=0; i<N; i++) {
        cin >> h;
        B.push_back(Info{h, 0});
    }
}

bool cmp(Info a, Info b) {
    return a.cnt > b.cnt;
}

int count_buildings() {
    for(int i=0; i<N; i++) {
        double max_g = -MAX;
        
        for(int j=i+1; j<N; j++) {
            int h = (B[j].h - B[i].h);
            int w = j - i;
            double g = (h * 1.0 / w);
        
            if(max_g < g) {
                max_g = g;
                B[i].cnt++; B[j].cnt++;
            }
        }
    }

    sort(B.begin(), B.end(), cmp);
    return B.front().cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    cout << count_buildings();
}
