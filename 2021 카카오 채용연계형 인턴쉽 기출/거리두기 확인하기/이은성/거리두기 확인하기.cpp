#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string p[5];
bool visited[25];
bool flag;

bool dfs(int i, int j, int depth){

    visited[(i * 5) + j] = true;

    if(depth != 0 && p[i][j] == 'P'){
        flag = true;
        return flag;
    }
    if(depth == 2){
        return flag;
    }

    if(i > 0 && p[i-1][j] != 'X' && !visited[(i-1)*5 + j]){
        dfs(i-1, j, depth+1);
        if(flag)
            return flag;
    }
    
    if(i < 4 && p[i+1][j] != 'X' && !visited[(i+1)*5 + j]){
        dfs(i+1, j, depth+1);
        if(flag)
            return flag;
    }
    
    if(j > 0 && p[i][j-1] != 'X' && !visited[i*5 + j-1]){
        dfs(i, j-1, depth+1);
        if(flag)
            return flag;
    }

    if(j < 4 && p[i][j+1] != 'X' && !visited[i*5 + j+1]){
        dfs(i, j+1, depth+1);
        if(flag)
            return flag;
    }

    return flag;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i = 0; i < places.size(); i++){
        for (int j = 0; j < places[i].size(); j++){
            p[j] = places[i][j];
        }

        flag = false;        
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(p[j][k] == 'P'){
                    memset(visited, false, 25);        
                    if(dfs(j, k, 0))
                        break;            
                }
            }
            if(flag)
                break;
        }
        if(flag)
            answer.push_back(0);
        else
            answer.push_back(1);
    }


    

    return answer;
}

int main(){

    vector<vector<string>> places={{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, 
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, 
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, 
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    solution(places);
    return 0;
}
