#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> users;
vector<int> emoticons;
vector<int> answer(2, 0);
int discount[4] = {40, 30, 20, 10};

struct purchase_info {
    int cost;
    bool is_plus;
};

struct result_info {
    int plus_cnt;
    int cost;
};

int calculate_discount(int cost, int discount) {
    return (cost * (100 - discount)) / 100;
}

void calculate_answer(vector<int> discounts) {
    vector<purchase_info> purchases(users.size(), purchase_info{0, false});
    
    for(int i=0; i<emoticons.size(); i++) {
        int cur_discount = discounts[i];
        int cur_cost = calculate_discount(emoticons[i], discounts[i]);
        
        for(int u=0; u<users.size(); u++) {
            if(purchases[u].is_plus) continue;
            
            int limit_discount = users[u][0];
            if(limit_discount > cur_discount) continue;
            
            int limit_cost = users[u][1];
            purchases[u].cost += cur_cost;
            if(purchases[u].cost >= limit_cost) {
                purchases[u].is_plus = true;
                purchases[u].cost = 0;
            }
        }
    }
    
    result_info result = result_info{0, 0};
    for(auto purchase_info: purchases) {
        if(purchase_info.is_plus) result.plus_cnt++;
        result.cost += purchase_info.cost;
    }
    
    if(result.plus_cnt > answer[0] || 
      (result.plus_cnt == answer[0] && result.cost > answer[1])) {
        answer[0] = result.plus_cnt;
        answer[1] = result.cost;
    }
}

void find_all_cases(vector<int> discounts) {
    if(discounts.size() == emoticons.size()) {
        calculate_answer(discounts);
        return;
    }
    
    for(int i=0; i<4; i++) {
        discounts.push_back(discount[i]);
        find_all_cases(discounts);
        discounts.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users_input, vector<int> emoticons_input) {
    users = users_input;
    emoticons = emoticons_input;
    vector<int> discounts;
    
    find_all_cases(discounts);
    
    return answer;
}