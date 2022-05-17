#include <bits/stdc++.h>
using namespace std;

bool check[51];
int answer;

struct info {
    string word;
    int cnt;
};

bool canSwitch(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            cnt++;
        }
    }
    if (cnt == 1) {
        return true;
    } else {
        return false;
    }
}

void bfs(string begin, string target, vector<string> words) {
    queue<info> q;
    q.push({begin, 0});
    
    while(!q.empty()) {
        string cur = q.front().word;
        answer = q.front().cnt;
        q.pop();
        
        for (int i = 0; i < words.size(); i++) {
            if (canSwitch(cur, words[i])) {
                if (words[i] == target) {
                    answer++;
                    break;
                }
                if (!check[i]) {
                    q.push({words[i], answer + 1});
                    check[i] = true;
                }
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    bool isPossible = false;
    
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == target) {
            isPossible = true;
        }
    }
    if (!isPossible) {
        return 0;
    }
    
    bfs(begin, target, words);
    
    return answer;
}
