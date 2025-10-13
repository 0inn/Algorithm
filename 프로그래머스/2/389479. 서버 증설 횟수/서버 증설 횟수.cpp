#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> servers(players.size(), 0);
    
    for(int i=0; i<players.size(); i++) {
        int need_server = players[i]/m;
        int add_server = (servers[i] > need_server) ? 0 : (need_server-servers[i]);
        answer += add_server;
        for(int j=0; j<k && i+j < players.size(); j++) {
            servers[i+j] += add_server;
        }
    }
    
    return answer;
}