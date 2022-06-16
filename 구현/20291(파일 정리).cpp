#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
string f,str;
map<string, int> files;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> f;
        for (int j = 1; j < f.size()-1; j++) {
            if (f[j] == '.') {
                str = f.substr(j + 1, f.size()-1);
                if (files.find(str) != files.end()) {
                    files[str]++;
                } else {
                    files.insert({str, 1});
                }
                break;
            }
        }
    }
    
    for (auto iter: files) {
        cout << iter.first << " " << iter.second << "\n";
    }
}
