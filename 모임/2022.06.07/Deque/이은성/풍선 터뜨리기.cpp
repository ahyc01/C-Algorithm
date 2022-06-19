#include <iostream>
#include <deque>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    int tmp;
    int c = 0;      // 현재 위치
    int bc = 0;     // 터트린 풍선
    bool check[1000] = {false,};    // 터진 풍선 = true

    deque<int> d;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        d.push_back(tmp);
    }

    tmp = 0;

    while(bc != n){
        while(tmp != 0){
            if(tmp > 0){
                c++;
                if(c == n)
                    c = 0;

                if(!check[c])
                    tmp--;
            }
            else{
                c--;
                if(c == -1)
                    c = n - 1;

                if(!check[c])
                    tmp++;
            }

        }
        check[c] = true;
        cout << c + 1 << ' ';
        tmp = d[c];
        bc++;
    }

    return 0;
}
