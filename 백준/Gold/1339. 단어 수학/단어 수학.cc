//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/10/25.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int N, ans, cur = 9;
int cnt[27]; // 알파벳 나온 개수
int number[27]; // 각 알파벳의 수
vector<string> words;

struct Compare {
    bool operator() (const char &a, const char &b) const{
        if(cnt[a-'A'] == cnt[b-'A']) return a > b;
        return cnt[a-'A'] > cnt[b-'A'];
    }
};

set<char, Compare> alphabets;

void input() {
    cin >> N;
    
    string word;
    for(int n=0; n<N; n++){
        cin >> word;
        words.push_back(word);
        
        for(int i=0; i<word.size(); i++) {
            char alphabet = word[i];
            cnt[alphabet-'A'] += pow(10, word.size() - i);
        }
    }
}

void make_numbers() {
    for(auto word: words) {
        for(auto alphabet: word) {
            alphabets.insert(alphabet);
        }
    }
    
    for(char alphabet: alphabets) {
        number[alphabet-'A'] = cur;
        cur--;
    }
}

void cal_ans() {
    for(int i=0; i<words.size(); i++) {
        for(int j=0; j<words[i].size(); j++) {
            char alphabet = words[i][j];
            int idx = words[i].size()-j-1;
            ans += number[alphabet-'A'] * pow(10, idx);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    make_numbers();
    cal_ans();
    cout << ans;
}
