#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool table[1000000];

string solution(int n, int k, vector<string> cmd){
    vector<int> e;
    vector<pair<int, int>> v;
    string answer = "";
    string strcnt;
    int tmp;
    int tmp2;
    int cnt;

    v.push_back({-1, 1});
    for(int i = 1; i < n; i++)
        v.push_back({i-1, i+1});
    v.back().second = -1;

    memset(table, true, n);

    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i][0] == 'U'){
            strcnt = "";
            for(int j = 2; j < cmd[i].length(); j++){
                strcnt+=cmd[i][j];
            }
            cnt = stoi(strcnt);
            for(;cnt!=0;cnt--){
                k = v[k].first;
            }
        }
        else if(cmd[i][0] == 'D'){
            strcnt = "";
            for(int j = 2; j < cmd[i].length(); j++){
                strcnt+=cmd[i][j];
            }
            cnt = stoi(strcnt);
            for(;cnt!=0;cnt--){
                k = v[k].second;
            }
        }
        else if(cmd[i][0] == 'C'){
            table[k] = false;
            e.push_back(k);
            if(v[k].first == -1){
                v[v[k].second].first = -1;
            }
            else if(v[k].second == -1){
                v[v[k].first].second = -1;
            }
            else{
                v[v[k].first].second = v[k].second;
                v[v[k].second].first = v[k].first;
            }
            if(v[k].second != -1)
                k = v[k].second;
            else
                k = v[k].first;
        }
        else if(cmd[i][0] == 'Z'){
            tmp = e.back();
            table[tmp] = true;
            e.pop_back();

            if(v[tmp].first == -1){
                tmp2=v[tmp].second;
                while(!table[tmp2]){
                    tmp2 = v[tmp2].second;
                }
                v[tmp].second = tmp2;
                v[tmp2].first = tmp;
            }
            else if(v[tmp].second == -1){
                tmp2=v[tmp].first;
                while(!table[tmp2]){
                    tmp2 = v[tmp2].first;
                }
                v[tmp].first = tmp2;
                v[tmp2].second = tmp;
            }

            else{
                tmp2=v[tmp].second;
                while(tmp2!=-1 && !table[tmp2]){
                    tmp2 = v[tmp2].second;
                }

                if(tmp2 == -1){
                    tmp2=v[tmp].first;
                    while(tmp2!=-1 && !table[tmp2]){
                        tmp2 = v[tmp2].first;
                    }
                    v[v[tmp2].second].first = tmp;
                    v[tmp].second = v[tmp2].second;
                    v[tmp].first = tmp2;
                    v[tmp2].second = tmp;
                }
                else{
                    v[v[tmp2].first].second = tmp;
                    v[tmp].first = v[tmp2].first;
                    v[tmp].second = tmp2;
                    v[tmp2].first = tmp;
                }
            }
            
        }
    }

    for(int i = 0; i < n; i++){
        if(table[i])
            answer.push_back('O');
        else
            answer.push_back('X');
    }
    return answer;
}

int main(){
    int n = 8, k = 2;
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
    string result;

    result = solution(n, k, cmd);
    cout << result;

    return 0;
}
