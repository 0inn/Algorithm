#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans, endTime;
vector<pair<int, int>> room;

int main() {
    cin >> N;
    for (int i = 0, s, e; i < N; i++) {
        cin >> s >> e;
        room.push_back({e, s});
    }
    sort(room.begin(), room.end());
    
    endTime = room[0].first;
    ans = 1;
    for (int i = 1; i < room.size(); i++) {
        if (endTime <= room[i].second) {
            ans++;
            endTime = room[i].first;
        }
    }
    cout << ans;
    
    return 0;
}
