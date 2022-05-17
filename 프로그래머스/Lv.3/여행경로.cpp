#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ticket;
vector<string> answer;
bool check[10001];
bool isAnswer;

void dfs(string start, int ticketCnt){
    answer.push_back(start);
    
    if (ticketCnt == ticket.size()) {
        isAnswer = true;
    }
    
    for (int i = 0; i < ticket.size(); i++) {
        if (check[i]) continue;
        if (ticket[i][0] == start) {
            check[i] = true;
            dfs(ticket[i][1], ticketCnt+1);
            
            if (!isAnswer) {
                answer.pop_back();
                check[i] = false;
            }
        }
    }
    
}


vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    dfs("ICN", 0);
    
    return answer;
}
