#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
        
    do {
        bool check = true;
        // ex. text = "N~F=0"
        for (string text: data) {
            int firstIdx = friends.find(text[0]);
            int secondIdx = friends.find(text[2]);
            int diff = abs(firstIdx - secondIdx)-1;
            int num = text[4] - '0';
            
            if (text[3] == '=') {
                if (num == diff) { continue; }
            } else if (text[3] == '>') {
                if (num < diff) { continue; }
            } else {
                if (num > diff) { continue; }
            }
            check = false;
            break;
        }
        if (check) { answer++; }
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}