#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, r, wins;
vector<int> answer;
vector<vector<int>> dice;

void printArr(vector<int> v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<int> aSum, bSum;

/// A, B 주사위 굴려서 나올 수 있는 합 구하기
void play(int idx, int sum, vector<int> v, bool isA) {
    if(idx == r) {
        isA ? aSum.push_back(sum) : bSum.push_back(sum);
        return;
    }

    for(int i=0; i<6; i++) {
        int cur = dice[v[idx]][i];
        play(idx+1, sum+cur, v, isA);
    }
}

// A, B 주사위 합 기준으로 승률 구하기
void battle(vector<int> a, vector<int> b) {
    aSum.clear();
    bSum.clear();
    
    play(0, 0, a, true);
    play(0, 0, b, false);
    
    sort(aSum.begin(), aSum.end());
    sort(bSum.begin(), bSum.end());
    
    int sum = 0;
    for(auto a: aSum) {
        for(auto b: bSum) {
            if(a > b) sum++;
            else break;
        }
    }
    if(sum > wins) {
        answer = a;
        for(int i=0; i<answer.size(); i++) answer[i]++;
        wins = sum;
    }
}

/// A가 가져가는 주사위 조합 구하기
void comb(int start, vector<int> a) {
    if(a.size() == r) {
        vector<int> b;
        for(int i=0; i<n; i++) {
            if(find(a.begin(), a.end(), i) == a.end()) b.push_back(i);
        }
        battle(a, b);
        return;
    }
    
    for(int i=start+1; i<n; i++) {
        a.push_back(i);
        comb(i, a);
        a.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dices) {
    dice = dices;
    n = dice.size();
    r = n / 2;
    
    vector<int> a;
    comb(-1, a);
    
    return answer;
}