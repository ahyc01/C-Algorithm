#include <iostream>

using namespace std;

int board[15][15];
int cnt;

bool checkcol(int r, int c, int n){
    for(int i = 0; i < n; i++){
        if(i == r)
            continue;
        if(board[i][c] == 1)
            return false;
    }
    return true;
}

bool checkdia(int r, int c, int n){
    for(int i = 1; i < n; i++){
        if(r + i < n && c + i < n && board[r + i][c + i] == 1)
            return false;
        if(r - i >= 0 && c - i >= 0 && board[r - i][c - i] == 1)
            return false;
        if(r + i < n && c - i >= 0 && board[r + i][c - i] == 1)
            return false;
        if(r - i >= 0 && c + i < n && board[r - i][c + i] == 1)
            return false;
    }
    return true;
}

void dfs(int r, int c, int n){
    if(r == n - 1 && checkcol(r, c, n) && checkdia(r, c, n)){
        cnt++;
        return;
    }
    if(checkcol(r, c, n) && checkdia(r, c, n)){
        for(int i = 0; i < n; i++){
            board[r + 1][i] = 1;
            dfs(r + 1, i, n);
            board[r + 1][i] = 0;
        }
    }
}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        board[0][i] = 1;
        dfs(0, i, n);
        board[0][i] = 0;
    }

    cout << cnt;
    return 0;
}
