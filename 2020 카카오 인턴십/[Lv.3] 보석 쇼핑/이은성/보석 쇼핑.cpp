#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

bool compare(VI &a, VI &b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

vector<int> solution(vector<string> gems){
    vector<int> answer = {0, 0};
    unordered_map<string, int> um;
    set<string> s(gems.begin(), gems.end());
    vector<VI> v;

    int left = 0, right = 0;

    while(true){
        if(s.size() == um.size()){
            v.push_back({right - 1 - left, left, right - 1});

            if(um[gems[left]] == left)
                um.erase(gems[left]);
            left++;

            if(right > gems.size())
                break;
        }
        else{
            if(right >=gems.size())
                break;
            um[gems[right]] = right;
            right++;
        }
    }

    sort(v.begin(), v.end(), compare);
    answer = {v[0][1] + 1, v[0][2] + 1};

    return answer;
}

int main(){

    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    solution(gems);
}
