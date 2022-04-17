#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;

LL calc(LL &a, LL &b, char op){
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    return a * b;
}
long long solution(string expression) {
    long long answer = 0;
    vector<vector<char>> order = {
        {'+', '-', '*'},
        {'+', '*', '-'},
        {'-', '+', '*'},
        {'-', '*', '+'}, 
        {'*', '+', '-'},
        {'*', '-', '+'}
    };
    vector<char> ops, tmp1;
    vector<LL> nums, tmp2;
    string tmp = "";

    for(auto i : expression){
        if(i == '+' || i == '-' || i == '*'){
            ops.push_back(i);
            nums.push_back(stoi(tmp));
            tmp = "";
        }
        else{
            tmp.push_back(i);
        }
    }
    nums.push_back(stoi(tmp));

    for(int i = 0; i < order.size(); i++){
        tmp1 = ops;
        tmp2 = nums;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < tmp1.size(); k++){
                if(tmp1[k] == order[i][j]){
                    tmp2[k] = calc(tmp2[k], tmp2[k+1], tmp1[k]);
                    tmp2.erase(tmp2.begin() + k + 1);
                    tmp1.erase(tmp1.begin() + k);
                    k--;
                }
            }
        }
        if (answer < abs(tmp2[0])){
            answer = abs(tmp2[0]);
        }
    }
    return answer;
}

int main(){
    string exp = "50*6-3*2";
    solution(exp);
    return 0;
}
