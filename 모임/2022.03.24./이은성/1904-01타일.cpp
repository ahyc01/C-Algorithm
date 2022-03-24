#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int n;
    
    cin >> n;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    if(n < 3){
        cout << v[n];
        return 0;
    }
    
    for(int i = 3; i <= n; i++){
        v.push_back((v[i-1] + v[i-2]) % 15746);
    }    
    
    cout << v[n];

    return 0;
}
