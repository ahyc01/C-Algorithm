#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m[26][26];
int d[26][26];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void dfs(int r, int c, int n, int cnt){
    int nr, nc;

    d[r][c] = cnt;
    for(int i = 0; i < 4; i++){
        nr = r + dr[i];
        nc = c + dc[i];
        if(nr >= 0 && nr < n && m[nr][nc] == 1 && d[nr][nc] == 0){
            dfs(nr, nc, n, cnt);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int cnt = 0, j;
    string str;

    for(int i = 0; i < n; i ++){
        cin >> str;
        j = 0;
        for(auto s:str){
            m[i][j] = s - '0';
            j++;
        }

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == 1 && d[i][j] == 0){
                cnt++;
                dfs(i, j, n, cnt);     
            }
        }
    }

    vector<int> v(cnt);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(d[i][j] != 0)
                v[d[i][j] - 1]++;
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for(auto i : v){
        cout << i << '\n';
    }

    return 0;
}
