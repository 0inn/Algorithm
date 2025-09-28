class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<>());

        for(int i=0; i<citations.size(); i++) {
            int c = citations[i];
            if(c < i+1) return i;
        }

        return citations.size();
    }
};