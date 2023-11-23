#include <string>
#include <vector>

using namespace std;

char alphabets[5] = {'A', 'E', 'I', 'O', 'U'};
int cnt = 0, ans = 0;

void find_word(string cur, string word) {
    if(cur == word) {
        ans = cnt;
        return;
    }
    
    cnt++;
    
    if(cur.size() == 5) return;
    
    for(auto alphabet: alphabets) {
        find_word(cur + alphabet, word);
    }
}

int solution(string word) {
    find_word("", word);
    
    return ans;
}