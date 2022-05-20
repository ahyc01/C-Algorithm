#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    for(auto move: moves){
        for(int i = 0; i < board.size(); i++){
            if(board[i][move - 1] == 0)
                continue;
            if(s.empty() || s.top() != board[i][move-1]){
                s.push(board[i][move-1]);
                board[i][move-1] = 0;
                break;
            }
            else{      
                s.pop();
                board[i][move-1] = 0;
                answer++;
                break;
            }
        }
    }
    return answer * 2;
}

int main(){
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    solution(board, moves);
    return 0;
}
