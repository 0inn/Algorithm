//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/13.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 10001

using namespace std;

int N, M, ans;
int book[MAX];

bool cmp(int a, int b) {
    return a < b;
}

void input() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        cin >> book[i];
    }
}

void make_their_position() {
    sort(book, book + N, cmp);

    for(int i=0; i<N;) {
        if(book[i] > 0) break;
        ans += abs(book[i]) * 2;
        i += M;
    }
    
    for(int i=N-1; i>=0;) {
        if(book[i] < 0) break;
        ans += abs(book[i]) * 2;
        i -= M;
    }
    
    int last_position = max(abs(book[0]), abs(book[N-1]));
    ans -= last_position;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    make_their_position();
    cout << ans;
}
