#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int tmp;
    int top;
    bool check = true;
    priority_queue<int> pq;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        pq.push(tmp);
    }

    for(int i = 0; i < m; i++){
        cin >> tmp;
        top = pq.top();
        pq.pop();
        top -= tmp;
        if(top < 0){
            check = false;
            break;
        }
        pq.push(top);
    }

    if(check)
        cout << 1;
    else
        cout << 0;
    return 0;
}
