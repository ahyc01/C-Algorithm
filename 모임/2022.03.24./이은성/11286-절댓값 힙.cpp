#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    priority_queue<pair<int, int>> pq;
    pair<int, int> p;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        
        if(x == 0){
            if(pq.empty())
                cout << 0 << '\n';
            else{
                cout << -pq.top().second << '\n';
                pq.pop();
            }
        }
        else{
            pq.push({-abs(x), -x});
        }
    }
}
