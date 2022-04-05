#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string s) {
    string answer = s;
    vector<string> number = {"zero", "one", "two", "three", "four", 
                             "five", "six", "seven", "eight", "nine"};
    
    for(int i=0; i<number.size(); i++){
        // 첫 번째 인자 : 반환할 대상, 두 번째 인자 : 정규표현식 개체(내가 찾고자 하는 문자), 세 번째 인자 : 바꿔줄 패턴
        answer = regex_replace(answer, regex(number[i]), to_string(i));
    }
    
    return stoi(answer);
}
