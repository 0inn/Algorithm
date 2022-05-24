#include <iostream>
#include <map>
using namespace std;

string str;
double total;
map<string, double> trees;

int main() {
    
    while(getline(cin,str)) {
        total++;
        if (trees.find(str) != trees.end()) {  // 중복된 경우
            trees[str] += 1;
        } else {
            trees[str] = 1;
        }
    }
    
    for (auto it = trees.begin(); it != trees.end(); it++) {
        cout << it->first << " ";
        cout << fixed;
        cout.precision(4);
        cout << (it->second/total) * 100 << "\n";
    }
    
    return 0;
}
