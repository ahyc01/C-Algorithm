#include <iostream>
#include <stack>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    int n;  cin >> n;
    int tmp;

    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        if(tmp == 0 && !s.empty()){
            s.pop();
        }
        else{
            s.push(tmp);
        }    
    }

    tmp = 0;
    while(!s.empty()){
        tmp += s.top();
        s.pop();
    }

    cout << tmp;


    return 0;
}
