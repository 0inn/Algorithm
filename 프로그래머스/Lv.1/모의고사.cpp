#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> answer;
vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> ans;
int tmp, person;

vector<int> solution(vector<int> answers) {
    for (int i = 1; i <= 3; i++) {
        tmp = 0;
        for (int j = 0; j < answers.size(); j++) {
            if (i == 1) {
                if(tmp == 5) { tmp = 0; }
                if(first[tmp] == answers[j]) { ans[1]++; }
            } else if (i == 2) {
                if(tmp == 8) { tmp = 0; }
                if(second[tmp] == answers[j]) { ans[2]++; }
            } else {
                if(tmp == 10) { tmp = 0; }
                if(third[tmp] == answers[j]) { ans[3]++; }
            }
            tmp++;
        }
    }
    
    for (int i = 1; i <= 3; i++) {
        if (person < ans[i]) {
            person = ans[i];
        }
    }
    
    for (int i = 1; i <= 3; i++) {
        if (person == ans[i]) {
            answer.push_back(i);
        }
    }
    
    return answer;
}
