#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
  
    vector<long long> tmp_calculation;
    vector<char> operators, loc;
    
    string temp = "";
    
    for(int i=0; i<expression.size(); i++){
        if(expression[i]=='+' || expression[i]=='*' || expression[i]=='-'){
            tmp_calculation.emplace_back(stoi(temp));
            temp = "";
            // 중복 제거한 연산자
            if(find(operators.begin(), operators.end(), expression[i]) == operators.end()){
                operators.emplace_back(expression[i]);
            }
            // 연산자 순서대로 위치확인
            loc.emplace_back(expression[i]);
        }
        else{
            temp += expression[i];
        }
    }
    tmp_calculation.emplace_back(stoi(temp));
    // 순열관련, 전체 순열을 출력하기 위해서는 오름, 내림차순 정렬이 한번 필요하다.
    // 정렬하지 않으면 삽입 정렬 처럼만 진행된다. next_permutation, prev_permutation
    // https://notepad96.tistory.com/entry/C-%EC%88%9C%EC%97%B4Permutation-nextpermutation
    sort(operators.begin(), operators.end());
    
    
    do{
        vector<long long> cal = tmp_calculation;
        vector<char> tmp_loc = loc;

        for(int i=0; i<operators.size(); i++){
            for(int j=0; j<tmp_loc.size(); j++){
                if(operators[i] == tmp_loc[j]){

                    if(tmp_loc[j] == '+'){
                        cal[j] = cal[j] + cal[j+1];
                    }
                    else if(tmp_loc[j] == '*'){
                        cal[j] = cal[j] * cal[j+1];
                    }
                    else if(loc[j] == '-'){
                        cal[j] = cal[j] - cal[j+1];
                    }
                    // cout << tmp_calculation[j] << endl;

                    cal.erase(cal.begin() + j+1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;

                }
            }
        }

        if(answer < abs(cal[0])){
            answer = abs(cal[0]);
        }
    }while(next_permutation(operators.begin(), operators.end()));
    
    // do{
    //     for(int i=0; i<operators.size(); i++){
    //         cout << operators[i] << "";
    //     }
    //     cout << endl;
    // }while(next_permutation(operators.begin(), operators.end()));
    
    return answer;
}
