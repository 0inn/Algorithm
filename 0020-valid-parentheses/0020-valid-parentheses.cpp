class Solution {
public:
    bool isValid(string s) {
        bool ans = false;
        vector<char> brackets;
        
        for (auto b: s) {
            if (brackets.empty()) {
                brackets.push_back(b);
                continue;
            }

            char last = brackets.back();
            switch (b) {
                case ')':
                    if(last == '(') brackets.pop_back();
                    else brackets.push_back(b);
                    break;
                case ']':
                    if (last == '[') brackets.pop_back();
                    else brackets.push_back(b);
                    break;
                case '}':
                    if (last == '{') brackets.pop_back();
                    else brackets.push_back(b);
                    break;
                default:
                    brackets.push_back(b);
            }
        }
        return brackets.empty();
    }
};