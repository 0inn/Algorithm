#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct UV {
    string u, v;
};

// u의 새로운 문자열 생성
string cal_new(string str) {
    string tmp = "";
    
    for(int i=1; i<str.size()-1; i++) {
        if(str[i] == '(') tmp += ')';
        else tmp += '(';
    }
    
    return tmp;
}

// u가 올바른 괄호 문자열인지 확인
bool check_if_correct(string str) {
    stack<char> st;
    
    for(int i=0; i<str.size(); i++) {
        if(st.empty() || str[i] == '(') st.push(str[i]);
        else {
            if(st.top() == '(') st.pop();
            else st.push(str[i]);
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

// 두 문자열 u, v로 분리
UV divide(string str) {
    int left = 0, right = 0;
    string u = "", v = "";
        
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') left++;
        else right++;
        u += str[i];
        
        if(left == right) {
            v = str.substr(i+1, str.size()-i);
            break;
        }
    }
    
    return UV{u, v};
}

string solution(string p) {
    string u = "", v = "", ans = "";
    
    // 1.
    if(p.empty()) return "";
    
    // 2.
    UV uv = divide(p);
    u = uv.u;
    v = uv.v;
    
    // 3.
    if(check_if_correct(u)) {
        // 3-1.
        ans = u + solution(v);
        return ans;
    } 
    
    // 4.
    else {
        ans = "("; // 4-1.
        ans += solution(v); // 4-2.
        ans += ")"; // 4-3.
        ans += cal_new(u); // 4-4.
        return ans; // 4-5.
    }
}