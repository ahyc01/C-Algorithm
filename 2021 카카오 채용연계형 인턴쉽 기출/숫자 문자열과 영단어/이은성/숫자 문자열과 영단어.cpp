#include <string>
#include <vector>

using namespace std;

string num[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int solution(string s){
    string result;
    string tmp;

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9')
            result+=s[i];
        else{
            for(int j = i; j < s.length(); j++){
                if(s[j] >= '0' && s[j] <= '9'){
                    i = j - 1;
                    break;
                }
                else{
                    tmp += s[j];
                    if(j == s.length() - 1)
                        i = j;
                }
            }
            
            for(int j = 0; j < 10; j++){
                if(tmp.find(num[j]) == 0){
                    result.append(to_string(j));
                    tmp.erase(0,num[j].length());
                    j = -1;
                }
            }

        }
    }

    return stoi(result);
}
