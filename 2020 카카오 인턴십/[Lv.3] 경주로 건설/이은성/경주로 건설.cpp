#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

typedef vector<int> VI;

int val[25][25][4];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    priority_queue<VI> pq;
    VI tmp;
    int n = board.size();
    int ni, nj;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < 4; k++)
                val[i][j][k] = -INF;

    if(board[0][1] != 1){
        pq.push({-100, 0, 0, 1});
        val[0][1][2] = -100;
    }
    if(board[1][0] != 1){
        pq.push({-100, 1, 1, 0});
        val[1][0][0] = -100;
    }

    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();

        if(tmp[2] == n - 1 && tmp[3] == n - 1){
            answer = -tmp[0];
            break;
        }

        for(int i = 0; i < 4; i++){
            ni = tmp[2] + di[i];
            nj = tmp[3] + dj[i];

            if( ni >= n || ni < 0 || nj >= n || nj < 0 || board[ni][nj] == 1 )
                continue;

            if(tmp[1] == 0){                                        // 가로 방향으로 온 경우
                if(di[i] == 0 && tmp[0] - 100 > val[ni][nj][i]){       // 다음 방향도 가로(직선)
                    val[ni][nj][i] = tmp[0] - 100;
                    pq.push({tmp[0] - 100, 0, ni, nj});
                }
                else if (di[i] != 0 && tmp[0] - 600 > val[ni][nj][i]){ // 다음 방향이 세로(코너)
                    val[ni][nj][i] = tmp[0] - 600;
                    pq.push({tmp[0] - 600, 1, ni, nj});
                }
            }
            else{                                                   // 세로 방향으로 온 경우
                if(dj[i] == 0 && tmp[0] - 100 > val[ni][nj][i]){       // 다음 방향도 세로(직선)
                    val[ni][nj][i] = tmp[0] - 100;
                    pq.push({tmp[0] - 100, 1, ni, nj});
                }
                else if (dj[i] != 0 && tmp[0] - 600 > val[ni][nj][i]){ // 다음 방향이 가로(코너)
                    val[ni][nj][i] = tmp[0] - 600;
                    pq.push({tmp[0] - 600, 0, ni, nj});
                }
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> board = {{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}};
    solution(board);
}
