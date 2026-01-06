class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dict[27] = {0,};
        for (auto m: magazine) {
            dict[int(m)-97]++;
        }
        for(auto r: ransomNote) {
            if(dict[(int(r)-97)] == 0) {
                return false;
            }
            dict[int(r)-97]--;
        }
        return true;
    }
};