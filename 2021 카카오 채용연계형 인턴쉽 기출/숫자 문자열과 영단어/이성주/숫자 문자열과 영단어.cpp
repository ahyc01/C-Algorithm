#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string s) {
    string answer = s;
    vector<string> number = {"zero", "one", "two", "three", "four", 
                             "five", "six", "seven", "eight", "nine"};
    
    for(int i=0; i<number.size(); i++){
        answer = regex_replace(answer, regex(number[i]), to_string(i));
    } 
    
    return stoi(answer);
}
