#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    int max;
    string tmp;
    map<string, int> um;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(um.count(tmp)){
            um[tmp]++;
        }
        else{
            um[tmp] = 0;
        }
    }

    max = -1;

    for(auto it = um.begin(); it != um.end(); it++){
        if(it->second > max){
            max = it->second;
            tmp = it->first;
        }
    }
    cout << tmp;

    return 0;
}
