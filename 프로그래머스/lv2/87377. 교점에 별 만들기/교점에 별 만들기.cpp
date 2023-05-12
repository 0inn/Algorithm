#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

vector<pair<ll, ll>> points;
vector<string> answer;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

bool xCmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.first < b.first;
}

bool yCmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

void calculate(ll a, ll b, ll e, ll c, ll d, ll f) {
    ll divider = a*d - b*c;
    
    if(divider == 0) return;
    if(((b*f - e*d) % divider) != 0 || ((e*c - a*f) % divider) != 0) return;
    
    ll x = (b*f - e*d) / divider;
    ll y = (e*c - a*f) / divider;
    points.push_back(make_pair(x, y));
}

vector<string> solution(vector<vector<int>> line) {
    for(ll i=0; i<line.size(); i++) {
        for(ll j=i+1; j<line.size(); j++) {
            ll a = line[i][0], b = line[i][1], e = line[i][2];
            ll c = line[j][0], d = line[j][1], f = line[j][2];
            calculate(a, b, e, c, d, f);
        }
    }
    
    sort(points.begin(), points.end(), cmp);
    points.erase(unique(points.begin(), points.end()), points.end());
    
    auto xm = minmax_element(points.begin(), points.end(), xCmp);
    auto ym = minmax_element(points.begin(), points.end(), yCmp);
   
    ll xmin = xm.first -> first, xmax = xm.second -> first;
    ll ymin = ym.first -> second, ymax = ym.second -> second;
    
    ll idx = 0;
    for(ll i=0; i<abs(ymax - ymin)+1; i++) {
        string str(abs(xmax - xmin)+1, '.');
        while(true) {
            if(i == points[idx].second + (-ymin)) {
                str[points[idx].first + (-xmin)] = '*';
                idx++;
            } else break;
        }
        answer.push_back(str);
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}