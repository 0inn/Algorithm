#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ans = "";
    
    while(n != 0) {
        int r = n % 3;
        n /= 3;

        if (r == 0) {
            ans = "4" + ans;
            n--;
        } else if (r == 1) {
            ans = "1" + ans;
        } else if (r == 2) {
            ans = "2" + ans;
        }
    }
    
    return ans;
}