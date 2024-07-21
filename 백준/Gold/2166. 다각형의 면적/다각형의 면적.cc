//
//  다각형의 면적.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/21/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
typedef long double ld;

using namespace std;

struct Point {
    int x, y;
};

int N;
vector<Point> v;
ld ans;

ld calculate(int i, int j) {
    ld a = v[0].x, b = v[0].y;
    ld c = v[i].x, d = v[i].y;
    ld e = v[j].x, f = v[j].y;
    
    return (a*d + c*f + e*b - c*b - e*d - a*f) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0,x,y; i<N; i++) {
        cin >> x >> y;
        v.push_back(Point{x, y});
    }
    
    for(int i=1; i<N-1; i++) {
        ans += calculate(i, i+1);
    }
    
    // fix to one decimal place
    cout << fixed;
    cout.precision(1);
    
    cout << abs(ans);
}
