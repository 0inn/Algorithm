//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/06/09.
//

#include <iostream>
#include <algorithm>
#define MAX 1000001

typedef long long ll;
using namespace std;

struct Point {
    ll x, y;
};

ll N;
Point arr[MAX];

bool compare(Point a, Point b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

// 선의 총 길이 구하기
ll cal_len() {
    ll start = arr[0].x, end = arr[0].y;
    ll cnt = 0;
    
    for(int i=1; i<N; i++) {
        if(arr[i].x <= end) end = max(end, arr[i].y);
        else {
            cnt += (end - start);
            start = arr[i].x;
            end = arr[i].y;
        }
    }
    
    return cnt + (end - start);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N;
    
    ll x, y;
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        arr[i] = Point{x, y};
    }
    
    // 오름차순 정렬
    sort(arr, arr+N, compare);
    
    cout << cal_len();
}
