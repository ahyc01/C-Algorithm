#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    return a.size() < b.size();
}
vector<int> solution(string s){
    vector<int> answer;
    vector<vector<int>> v;
    string tmp;
    int cnt = -1;
    bool flag = false;

    for(int i = 1; i < s.length() - 1; i++){
        if(s[i] == '{'){
            flag = true;
            v.push_back({});
            cnt++;
            continue;
        }
        else if(s[i] == '}'){
            flag = false;
            v[cnt].push_back(stoi(tmp));
            tmp = "";
            continue;
        }

        if(flag){
            if(s[i] != ',')
                tmp.push_back(s[i]);
            else{
                v[cnt].push_back(stoi(tmp));
                tmp = "";
            }
        }
    }

    sort(v.begin(), v.end(), compare);

    answer.push_back(v[0][0]);

    for(auto i : v){
        for(int j = 0; j < i.size(); j++){
            flag = true;
            for(auto k : answer){
                if(i[j] == k)
                    flag = false;
            }
            if(flag){
                answer.push_back(i[j]);
            }
        }
    }

    return answer;
}

int main(){
    string s = 	"{{20,111},{111}}";
    solution(s);
    return 0;
}
