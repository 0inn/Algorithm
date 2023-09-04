//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/04.
//

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10001

using namespace std;

struct Answer {
    int third, fourth;
};

int T, K;
string words;
int alphabets[27];

Answer solution(int k, string words) {
    int minValue = MAX, maxValue = 0;
    
    int end = 0;
    for(int i=0; i<words.size(); i++) {
        alphabets[words[i]-'a']++;
    }
    
    for(int i=0; i<words.size(); i++) {
        if(alphabets[words[i]-'a'] < K) continue;

        int cnt = 0;
        for(int j=i; j<words.size(); j++) {
            if(words[i] == words[j]) cnt++;
            if(cnt == K) {
                int diff = j - i + 1;
                minValue = min(minValue, diff);
                maxValue = max(maxValue, diff);
                break;
            }
        }
    }

    return Answer { minValue, maxValue };
}

void output(Answer ans) {
    if (ans.third == MAX) {
        cout << -1 << "\n";
    } else {
        cout << ans.third << " " << ans.fourth << "\n";
    }
}

void input() {
    cin >> T;
    
    while(T--) {
        cin >> words >> K;
        output(solution(K, words));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
}
